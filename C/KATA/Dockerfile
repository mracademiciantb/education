FROM ubuntu:latest

# Install the necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    libjpeg-dev \
    gcc \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*

# Copy the project into the container
COPY . /app

# Set the working directory to /app
WORKDIR /app

# Change permissions for the image file
RUN chmod +r /app/data/square.png

# Specify the path to search for header files
ENV C_INCLUDE_PATH=/app/src/include

# Compile the server code
RUN gcc -o kata /app/src/main.c /app/src/handlers/neural_network.c /app/src/handlers/image_processor.c -I/app/src/include/handlers -ljpeg -lm

# Command to run
CMD ["./kata"]
