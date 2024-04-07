from PIL import Image
import os

def normalize_images(source_dir, target_dir, target_size=(128, 128)):
    """
    Нормалізує всі зображення в папці source_dir, змінюючи їх розмір до target_size,
    і зберігає оброблені зображення в папці target_dir.
    """
    if not os.path.exists(target_dir):
        os.makedirs(target_dir)
    
    for filename in os.listdir(source_dir):
        if filename.lower().endswith(('.png', '.jpg', '.jpeg')):
            img_path = os.path.join(source_dir, filename)
            img = Image.open(img_path)
            
            # Зміна розміру зображення
            img_resized = img.resize(target_size, Image.Resampling.LANCZOS)
            
            # Збереження нормалізованого зображення
            target_path = os.path.join(target_dir, filename)
            img_resized.save(target_path)

# Вказівка шляхів до папок
source_directory = '/Users/mandalorian/Dev/education/Python/kata/data/train/data2'  # Замініть на ваш шлях до вихідних зображень
target_directory = '/Users/mandalorian/Dev/education/Python/kata/data/train_normalized/circle'  # Замініть на ваш шлях для збереження нормалізованих зображень

# Виклик функції для нормалізації зображень
normalize_images(source_directory, target_directory)
