# data_preparation.py
def prepare_data(csv_path, train_images_folder_path, valid_images_folder_path):
    import pandas as pd
    import tensorflow as tf
    from tensorflow.keras.preprocessing.image import ImageDataGenerator
    from sklearn.model_selection import train_test_split
    import os
    from pathlib import Path

    # Load data from CSV with the correct separator
    df = pd.read_csv(csv_path)
    print(df.head())  # Виведення перших кількох рядків DataFrame
    # Приклад перевірки одного файлу
    sample_file = df['image_name'].iloc[0]
    file_path = os.path.join(train_images_folder_path, sample_file)
    if not Path(file_path).is_file():
        print(f"Файл не знайдено: {file_path}")
    else:
        print(f"Файл існує: {file_path}")
    # Split data into training and validation sets
    train_df, val_df = train_test_split(df, test_size=0.2) # 20% of data for validation

    def load_and_process_image(file_path):
        # Load the image
        img = tf.io.read_file(file_path)
        img = tf.image.decode_jpeg(img, channels=3)
        # Image processing: resizing, cropping, and normalization
        img = tf.image.resize_with_pad(img, target_height=128, target_width=128)
        img = tf.cast(img, tf.float32) / 255.0
        assert img.dtype == tf.float32
        print(f"Type of the image tensor: {img.dtype}")

        return img

    # Image generators for training and validation sets
    train_datagen = ImageDataGenerator(preprocessing_function=load_and_process_image)
    val_datagen = ImageDataGenerator(preprocessing_function=load_and_process_image)

    # Configuration for generators with corrected target_size
    train_generator = train_datagen.flow_from_dataframe(
        dataframe=train_df,
        directory=train_images_folder_path,  # Path to training images
        x_col='image_name',
        y_col='label_name',
        target_size=(128, 128),  # Corrected target_size
        class_mode='categorical',
        batch_size=32
    )

    val_generator = val_datagen.flow_from_dataframe(
        dataframe=val_df,
        directory=valid_images_folder_path,  # Path to validation images
        x_col='image_name',
        y_col='label_name',
        target_size=(128, 128),  # Corrected target_size
        class_mode='categorical',
        batch_size=32
    )
    
    return train_generator, val_generator
