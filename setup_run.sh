#!/bin/bash

ENV_NAME="raycasting_env"
PYTHON_SCRIPT="ray.py"
LIBOUT="libraycasting.so"
LIBS="numpy pillow matplotlib"

echo "Creating virtual environment..."
python3 -m venv $ENV_NAME

echo "Activating virtual environment..."
source $ENV_NAME/bin/activate

echo "Installing required libraries..."
pip install $LIBS

echo "Compiling C library..."
make

echo "Running Python script..."
python3 $PYTHON_SCRIPT

echo "Cleaning..."

# Desativar o ambiente virtual
deactivate
make clean
rm -rf $ENV_NAME
