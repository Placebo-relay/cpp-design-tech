 # Use an official Python runtime as a base image
 FROM python:3.8

 # Set the working directory in the container
 WORKDIR /app

 # Install C++ tools and libraries
 RUN apt-get update && apt-get install -y build-essential

 # Install Jupyter Lab
 RUN pip install jupyterlab

 # Install xeus-cling for C++ support
 RUN conda install xeus-cling -c conda-forge

 # Set the default command to start Jupyter Lab
 CMD ["jupyter", "lab", "--ip=0.0.0.0", "--allow-root"]
 
