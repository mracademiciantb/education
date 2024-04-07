import os
import torch
from torch import nn
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms
import pandas as pd
from PIL import Image
import torch.optim as optim
import json
from torch import tensor

class CustomImageDataset(Dataset):
    def __init__(self, annotations_file, img_dir, transform=None):
        self.img_labels = pd.read_csv(annotations_file)
        self.img_dir = img_dir
        self.transform = transform
        # Create dictionary for converting word labels to numbers
        self.label_to_idx = {'Circle': 0, 'Triangle': 1, 'Square': 2}

    def __len__(self):
        return len(self.img_labels)

    def __getitem__(self, idx):
        img_path = os.path.join(self.img_dir, self.img_labels.iloc[idx, 5])
        image = Image.open(img_path).convert('RGB')
        label_text = self.img_labels.iloc[idx, 0]
        # Conwer text lables to number
        label = self.label_to_idx[label_text]
        if self.transform:
            image = self.transform(image)
        label = torch.tensor(label, dtype=torch.long)
        return image, label




transform = transforms.Compose([
    transforms.Resize((128, 128)),
    transforms.ToTensor(),
])

#path to train data
dataset = CustomImageDataset(annotations_file='/Users/mandalorian/Dev/education/Python/kata/data/train_normalized/labels_circles.csv', img_dir='/Users/mandalorian/Dev/education/Python/kata/data/train_normalized/circle', transform=transform)

train_loader = DataLoader(dataset, batch_size=64, shuffle=True)

class SimpleCNN(nn.Module):
    def __init__(self):
        super(SimpleCNN, self).__init__()
        self.conv1 = nn.Conv2d(3, 32, kernel_size=3, stride=1, padding=1)
        self.conv2 = nn.Conv2d(32, 64, kernel_size=3, stride=1, padding=1)
        self.conv3 = nn.Conv2d(64, 128, kernel_size=3, stride=1, padding=1)
        self.pool = nn.MaxPool2d(kernel_size=2, stride=2, padding=0)
        self.fc1 = nn.Linear(128 * 16 * 16, 512)
        self.fc2 = nn.Linear(512, 3) # for only 3 class
        self.relu = nn.ReLU()

    def forward(self, x):
        x = self.pool(self.relu(self.conv1(x)))
        x = self.pool(self.relu(self.conv2(x)))
        x = self.pool(self.relu(self.conv3(x)))
        x = x.view(-1, 128 * 16 * 16)
        x = self.relu(self.fc1(x))
        x = self.fc2(x)
        return x

model = SimpleCNN()



def predict_image(model, image_path):
    transform = transforms.Compose([
        transforms.Resize((128, 128)),
        transforms.ToTensor(),
    ])
    
    image = Image.open(image_path)
    image = transform(image).unsqueeze(0)  # Adding a batch dimension

    output = model(image)
    _, predicted = torch.max(output, 1)
    
    classes = ['Circle', 'Triangle', 'Square']
    return classes[predicted[0]]

def run_model(model, config_path='model_config.json'):
    if not os.path.exists(config_path):
        print("Configuration file not found. Please train the model first.")
        return

    with open(config_path, 'r') as f:
        config = json.load(f)
    
    model.load_state_dict(torch.load(config['model_state_dict']))

    #folder_path='/Users/mandalorian/Dev/education/Python/kata/data/enter_data'
    folder_path = input("Enter the path to the folder with the images:")
    if not os.path.exists(folder_path):
       print("The specified folder does not exist. Please check the path.")
       return
    
    files = [f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f))]
    for i, file in enumerate(files):
        print(f"{i + 1}. {file}")
    
    file_choice = int(input("Select the file number to recognize:")) - 1
    if file_choice < 0 or file_choice >= len(files):
        print("Incorrect file selection.")
        return
    
    selected_file_path = os.path.join(folder_path, files[file_choice])
    result = predict_image(model, selected_file_path)
    print(f"Result: {result}")

def init_dataset():
    transform = transforms.Compose([
        transforms.Resize((128, 128)),
        transforms.ToTensor(),
    ])
    dataset = CustomImageDataset(
        annotations_file='/Users/mandalorian/Dev/education/Python/kata/data/train_normalized/labels_circles.csv', 
        img_dir='/Users/mandalorian/Dev/education/Python/kata/data/train_normalized/circle', 
        transform=transform
    )
    return DataLoader(dataset, batch_size=64, shuffle=True)

# Training function
def train_model(train_loader):
    model = SimpleCNN()
    optimizer = optim.Adam(model.parameters(), lr=0.001)
    criterion = nn.CrossEntropyLoss()
    epochs = 10

    for epoch in range(epochs):
        for images, labels in train_loader:
            optimizer.zero_grad()
            outputs = model(images)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
        print(f'Epoch {epoch+1}, Loss: {loss.item()}')
    
    # Save the model (you can also save the training parameters)
    torch.save(model.state_dict(), 'model_state_dict.pth')
    
    # Creating a configuration file
    # Збереження конфігураційного файлу
    config_path = '/Users/mandalorian/Dev/education/Python/kata/model_config.json'
    config = {'epochs': epochs, 'model_state_dict': 'model_state_dict.pth'}
    with open(config_path, 'w') as f:
        json.dump(config, f)

    #config = {'epochs': epochs}
    #with open('config.json', 'w') as f:
    #   json.dump(config, f)
    print("The training is complete and the configuration file is created.")
    print("Enjoy;)")

# Main function
def main():
    print("Congratulations! Choose an option:")
    print("1: Train the model")
    print("2: Run the model")
    choice = input("Enter your choice (1 or 2): ")
    
    if choice == '1':
        train_loader = init_dataset()
        train_model(train_loader)
    elif choice == '2':
        # Створюємо екземпляр моделі
        model = SimpleCNN()
        # Викликаємо run_model() з параметром model
        run_model(model)
    else:
        print("Wrong choice.")


if __name__ == "__main__":
    main()