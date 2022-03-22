# automatic-error-code-detector

This repository contains a ROS package that detects error codes automatically. It warns the user about the error and stops the robot's autonomous navigation. You can build and run it as a ROS package, or as a docker container.

## Clone the repository

```bash
  git clone https://github.com/AlaHammouda/automatic-error-code-detector.git
  cd automatic-error-code-detector
```

## Build and run the error_detection package

Copy error_detection package to your catkin_ws/src folder and run:

```bash
  catkin build error_detection
```

Now, you can run the error detection node with:

```bash
  roslaunch error_detection error-detection.launch
```

## Use a docker container to run the error_detection package

Build the docker image:

```bash
  docker build -t error-detection .
```

Run error_detection container:

```bash
  docker-compose up
```

Remove the container:

```bash
  docker-compose down