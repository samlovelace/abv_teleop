# abv teleop

Teleop program to remote control the abv

## Install

Clone the abv_controller repo at https://github.com/samlovelace/abv_controller.git and follow the install instructions for that repo.
It will handle installation and compilation of this repo.
If this repo is already cloned, from the root of the workspace compile using colcon

```bash
colcon build --packages-select abv_teleop
```

## Run

Once compiled, run the executable

```bash
ros2 run abv_teleop abv_teleop
```
