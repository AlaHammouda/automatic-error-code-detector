FROM ros:melodic-ros-base

ENV DEBIAN_FRONTEND noninteractive
SHELL ["/bin/bash", "-c"]

ENV CATKIN_WS_PATH /home/ala/catkin_ws
WORKDIR $CATKIN_WS_PATH

RUN echo "-- creating workspace" && \
    apt-get update && apt-get install -y --no-install-recommends \
    python3-catkin-tools && \
    mkdir src && \
    source /opt/ros/melodic/setup.bash && \
    catkin init && \
    catkin build 

COPY . $CATKIN_WS_PATH/src
RUN echo "-- build error detection package" && \
    source /opt/ros/melodic/setup.bash && \
    catkin build error_detection

ENTRYPOINT ["/bin/bash", "-c" , "source /opt/ros/melodic/setup.bash && \
    source /home/ala/catkin_ws/devel/setup.bash && \
    roslaunch error_detection error-detection.launch"]

