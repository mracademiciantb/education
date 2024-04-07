import tensorflow as tf
from tensorflow.keras import layers, models
from data_preparation import prepare_data  # Ensure data_preparation.py is in the same directory or in PYTHONPATH
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing.image import img_to_array, load_img
import numpy as np
import os
import pandas as pd

def choose_image_from_directory(directory):
    """Дозволяє користувачу вибрати зображення з папки."""
    images = [file for file in os.listdir(directory) if file.lower().endswith(('.png', '.jpg', '.jpeg'))]
    if not images:
        return None  # Якщо зображень немає, повертаємо None
    
    print("Choose an image to predict:")
    for index, image in enumerate(images):
        print(f"{index + 1}: {image}")
    
    choice = input("Enter the number of the image: ")
    try:
        choice_index = int(choice) - 1
        if 0 <= choice_index < len(images):
            return os.path.join(directory, images[choice_index])
        else:
            print("Invalid choice. Please enter a valid number.")
            return None
    except ValueError:
        print("Please enter a number.")
        return None


# Define the input size of the image
input_shape = (128, 128, 3)  # For color images, (height, width, channels)

def create_model(input_shape):
    # Create the model with the adjusted output layer for 3 classes
    model = models.Sequential([
        layers.Conv2D(32, (3, 3), activation='relu', input_shape=input_shape),
        layers.MaxPooling2D((2, 2)),
        layers.Conv2D(64, (3, 3), activation='relu'),
        layers.MaxPooling2D((2, 2)),
        layers.Conv2D(64, (3, 3), activation='relu'),
        layers.Flatten(),
        layers.Dense(64, activation='relu'),
        layers.Dense(3, activation='softmax')  # Adjusted for 3 classes
    ])
    
    model.compile(optimizer='adam',
                  loss='sparse_categorical_crossentropy',
                  metrics=['accuracy'])
    return model

# Later, when predicting:


# Ensure your data preparation function correctly processes the data for these three classes

print("----------------------------------")
print("         Hi! I'm kata")
print("Model for recognizing objects, ver 0.1 from 03.03.2024")
print("----------------------------------")
print("To start model print 1. For learning: 2")

#chet data:
#print(df.head())  # Виведення перших кількох рядків DataFrame


inputUsr = input()  # This line was missing to actually capture user input

if(inputUsr == '2'):
    model = create_model(input_shape)

    # Set appropriate paths for your case
    csv_path = '/app/data/train_normalized/labels_circles.csv'
    train_images_folder_path = '/app/data/train_normalized/circle'
    valid_images_folder_path = '/app/data/train_normalized/circle_valid'

    train_generator, val_generator = prepare_data(csv_path, train_images_folder_path, valid_images_folder_path)


    # Train the model
    model.fit(train_generator, validation_data=val_generator, epochs=5)
    model.save('my_model.h5')  # Saves the entire model, including architecture, weights, and training configuration
    print("Architecture, scales, and configuration were saved as 'my_model.h5'")
else:
    try:
        model = load_model('my_model.h5')  # Loads the model
        print("Model was loaded successfully")
    except IOError:
        print("Model could not be loaded. Ensure 'my_model.h5' exists.")
        model = create_model(input_shape)  # Optionally create a new model if the saved one doesn't exist

def load_and_prepare_image(image_path, target_size=(128, 128)):
    """Load and prepare an image for prediction."""
    img = load_img(image_path, target_size=target_size)
    img = img_to_array(img)
    img = img.reshape(1, *target_size, 3)  # Reshape for model (adding batch dimension)
    img = tf.cast(img, tf.float32) / 255.0  # Ensure the data type is float32
    return img

def predict_image(model, image_path):
    """Predict the class of an image."""
    img = load_and_prepare_image(image_path)
    prediction = model.predict(img)
    # Assuming your model outputs softmax probabilities
    predicted_class = np.argmax(prediction, axis=1)
    return predicted_class

# Assuming '1' is for prediction
if inputUsr == '1':
    try:
        model = load_model('my_model.h5')  # Ensure the model is loaded
        print("Model loaded successfully.")
        
        images_folder_path = 'data/enter_data'
        image_path = choose_image_from_directory(images_folder_path)

        #class_names = ['клас1', 'клас2', 'клас3', 'клас4', 'клас5', 'клас6', 'клас7',  'клас8', 'клас9', 'клас10']
        class_names = ['Circle', 'Square', 'Triangle']  # Updated class names

        if image_path:
            predicted_class = predict_image(model, image_path)
            print(f"Predicted class: {class_names[predicted_class]}")
        else:
            print("No image was selected.")

    except IOError:
        print("Model could not be loaded. Ensure 'my_model.h5' exists.")
# Print the model architecture
model.summary()