import os

def rename_files(directory):
    # Отримуємо список файлів в директорії
    files = [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]
    
    # Сортуємо файли за назвою для послідовного перейменування
    files.sort()
    
    # Визначаємо формат назви файлів. Наприклад, "image_1.jpg"
    # Для збереження початкового розширення файлу використовуємо splitext
    for index, file in enumerate(files, start=1):
        file_extension = os.path.splitext(file)[1]  # Розширення файлу
        new_filename = f"image_{index}{file_extension}"
        
        # Формуємо повний шлях до старого і нового файлу
        old_file = os.path.join(directory, file)
        new_file = os.path.join(directory, new_filename)
        
        # Перейменовуємо файл
        os.rename(old_file, new_file)
        print(f"Renamed {file} to {new_filename}")

# Вкажіть шлях до вашої директорії з файлами
directory_path = "/Users/mandalorian/Dev/education/Python/kata/data/train_normalized/circle"
rename_files(directory_path)
