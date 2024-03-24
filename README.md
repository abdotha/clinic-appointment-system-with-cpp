# Clinic Appointment System with Text File Database

This is a clinic appointment system implemented in C++ with database functionality using text files and the `fstream` library. Patients can book appointments with doctors, and administrators can manage doctors and view doctor schedules.

## Features

- Patients can choose a doctor and book an appointment time.
- Administrators can add new doctors, delete doctors, and view doctor schedules.

## Database Setup

1. Ensure you have access to text files for storing doctor names and appointment schedules.
2. Each doctor will have two corresponding text files:
   - One for storing the doctor's name (e.g., `dr_smith.txt`, `dr_johnson.txt`, etc.).
   - Another for storing the booked appointment times (e.g., `dr_smith_schedule.txt`, `dr_johnson_schedule.txt`, etc.).

## How to Use

### Patient Mode

1. Run the program.
2. Choose the patient mode.
3. Follow the prompts to select a doctor and book an appointment time.

### Admin Mode

1. Run the program.
2. Choose the admin mode.
3. Follow the prompts to add a doctor, delete a doctor, or view doctor schedules.

## Usage Instructions

### Patient Mode

1. Select the option to book an appointment.
2. Choose a doctor from the available list.
3. Choose an available time slot for the appointment.
4. Provide necessary information for booking the appointment.
5. Confirmation of appointment booking will be displayed.

### Admin Mode

1. Select the option to enter admin mode.
2. Choose from the available administrative actions:
   - Add a new doctor.
   - Delete an existing doctor.
   - View the schedule of a particular doctor.
3. Follow the prompts to perform the selected action.

## Requirements

- C++ compiler

## Running the Program

1. Clone this repository.
2. Ensure you have access to the required text files for database operations.
3. Compile the source code using a C++ compiler.
4. Run the executable file generated.



### Patient Mode

