# Student Management System

A command-line application for maintaining student records. You can add and manage students, search and sort the records, calculate results, and save or load data from a text file.

## Requirements

- Python 3.12 or newer
- No third-party packages are required

## Setup and run

1. Install Python 3.12 or newer if it is not already installed.
2. Open a terminal in the folder containing `main.py`.
3. Start the application:

   ```bash
   python main.py
   ```

   On Windows, you can also use:

   ```powershell
   py -3.12 main.py
   ```

There is no separate build step. Run the program from the project folder so it can find the `data` folder.

## Main menu

When the program starts, it displays the main menu and waits for you to enter a menu number.

| Option | What it does |
|---|---|
| 1. Add Student | Prompts for the student's name, roll number, age, subjects and marks, then skills separated by commas. |
| 2. View All Students | Shows the student list, then asks for a roll number to display that student's subjects, marks and skills. |
| 3. Search Students | Opens the Search submenu. |
| 4. Sort Students | Opens the Sort submenu. |
| 5. Update Student Details | Asks for a roll number, then lets you update the student's name or age. |
| 6. Delete Student Details | Asks for a roll number and removes the matching student record. |
| 7. Show Result | Asks for a roll number and displays the student's total marks, average percentage, grade and pass/fail status. |
| 8. Save Data | Saves the current student records to `data/student.txt`. |
| 9. Load Data | Loads records from `data/student.txt`, replacing the records currently in memory. |
| 10. Exit | Closes the application. Changes are not saved automatically. |

## Submenus

### Search Students

Choose an option to search by:

1. Roll number
2. Name
3. Subject
4. Skill
5. Back to the main menu

### Sort Students

Choose an option to display students sorted by:

1. Roll number
2. Name
3. Average percentage
4. Attendance — this option is not implemented yet
5. Back to the main menu

The sorted list is displayed from lowest to highest for numeric fields such as roll number and percentage.

### Update Student Details

After entering a student's roll number, choose:

1. Update name
2. Update age
3. Back

## Results

The application adds the student's marks to calculate the total. It calculates the percentage as the average of the marks entered, treating each subject equally.

Grades are assigned using these thresholds:

| Average percentage | Grade |
|---:|:---|
| 90 and above | A+ |
| 80–89.99 | A |
| 70–79.99 | B |
| 60–69.99 | C |
| 50–59.99 | D |
| 40–49.99 | E |
| Below 40 | F |

A grade of F is reported as **FAIL**. Any other grade is reported as **PASS**.

## How the program is organized

The application keeps student records in a list while it is running. Each student record contains a name, roll number, age, subjects, marks and skills.

`main.py` displays the main menu and directs each choice to the appropriate function. The other modules handle the application's specific tasks:

- `student.py` — adds, displays, updates and deletes student records
- `search.py` — searches student records
- `sort.py` — sorts and displays student records
- `result.py` — calculates totals, percentages, grades and pass/fail status
- `file_manager.py` — saves records to and loads records from the data file

## Project structure

```text
Student_Management_System/
├── main.py
├── student.py
├── search.py
├── sort.py
├── result.py
├── file_manager.py
└── data/
    └── student.txt
```

## Saving and loading data

Records are stored in `data/student.txt`. Choose **Save Data** after making changes to keep them for the next session. Choose **Load Data** to read the saved records into the current session; loading replaces the records already in memory.