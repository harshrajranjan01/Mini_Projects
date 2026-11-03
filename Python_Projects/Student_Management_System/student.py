

def add_student(students):
    # Dictionary of student
    student = {
        "name": "",
        "roll": None,
        "age": None,
        "subjects": (),
        "marks": [],
        "skills": set()
    }
    # input data and modify the dictionary
    student["name"] = input("Enter Your Name: ")
    student["roll"] = int(input("Enter Your Roll No: "))
    student["age"] = int(input("Enter Your age: "))

    number_of_subjects = int(input("Ente number of subjects: "))
    for i in range(0, number_of_subjects):

        subject = input(f"Enter Subject {i+1}: ")
        student["subjects"] = student["subjects"] + (subject,)

        mark = int(input(f"Enter marks of {subject}: "))
        student["marks"].append(mark)

    skill_set = input("Enter Skills seperated by commas(,): ")

    student["skills"].update(skill.strip() for skill in skill_set.split(","))

    # Add the student dictionary data to students[] list
    students.append(student)


def view_all_students(students):
    print("-----------------------------------------")
    print("Name              Roll             Age   ")
    print("-----------------------------------------")

    for std in students:
        print(f"{std["name"]:<18}", f"{std["roll"]:<17}" f"{std["age"]}")

    roll_view = int(input("View Details, Enter Roll No: "))
    for std in students:
        if (roll_view == std["roll"]):
            print(
                f"\nRoll No: {std["roll"]} \nName: {std["name"]} \nAge: {std["age"]}\n")

            print("Subjects: ")
            for i, subject in enumerate((std["subjects"]), start=1):
                print(f"{i}. {subject}")

            print("\n")
            i = 1
            print("Marks: ")
            for i, (subject, mark) in enumerate(zip(std["subjects"], std["marks"]), start=1):
                print(f"{i}. {subject}: {mark}")
                i = i+1
            print("\n")

            print("Skills: ")
            for i, skill in enumerate(std["skills"], start=1):
                print(f"{i}. {skill}")


def update_student(students):
    roll_for_update = int(input("Enter Roll No to update: "))
    for std in students:
        if (std["roll"] == roll_for_update):
            print("\nStudent found!!")
            print("Name:", std["name"])
            print("Roll No:", std["roll"])
            print("Age:", std["age"])

            print("\nWhat do you want to update?")
            print("1. Update Name: ")
            print("2. Update age: ")
            print("3. Back ")

            choice3 = int(input("Enter Your Choice: "))
            if (choice3 == 1):
                updated_name = input("Enter Updating Name: ")
                std["name"] = updated_name

            elif (choice3 == 2):
                updated_age = int(input("Enter Updating age: "))
                std["age"] = updated_age

            elif (choice3 == 3):
                return

            else:
                print("Enter Valid Choice")

        else:
            print("Student Not found!!")


def delete_student(students):
    roll_for_update = int(input("Enter Roll No of student to delete: "))
    for std in students:
        if (std["roll"] == roll_for_update):
            print("\nDeleting Student")
            print("Name:", std["name"])
            print("Roll No:", std["roll"])
            print("Age:", std["age"])
            students.remove(std)
            
