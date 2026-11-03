from result import *

def sort_students(students):
    while True:
        print("\nSORT STUDENTS")
        print("----------------")
        print("1. Sort by Roll Number")
        print("2. Sort by Name")
        print("3. Sort by Percentage")
        print("4. Sort by Attendance")
        print("5. Back")

        choice4 = int(input("Enter Your Choice: "))

        if choice4 == 1:
            sorted_students = sorted(students, key=lambda std: std["roll"])

        elif choice4 == 2:
            sorted_students = sorted(
                students, key=lambda std: std["name"].lower())

        elif choice4 == 3:
            sorted_students = sorted(
                students, key=lambda std: result.calculate_percentage(std["marks"]))

        elif choice4 == 4:
            print("Coming Soon!!!")
            continue

        elif choice4 == 5:
            break

        else:
            print("Enter Valid Choice")
            continue

        print("\n" + "-" * 45)
        print(f"{'Name':<20}{'Roll':<12}{'Percentage':<12}")
        print("-" * 45)

        for std in sorted_students:
            percentage = result.calculate_percentage(std["marks"])
            print(
                f"{std['name']:<20}"
                f"{std['roll']:<12}"
                f"{percentage:.2f}%"
            )

