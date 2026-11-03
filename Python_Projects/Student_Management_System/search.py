
def search_by_roll(roll_to_search, students):
    for std in students:
        if (roll_to_search == std["roll"]):
            print("\nStudent found!! \n")

            # Printing Student Details
            print("Name: ", std["name"])
            print("Roll No: ", std["roll"])
            print("Age: ", std["age"], "\n")


def search_by_name(name_to_search, students):
    for std in students:
        if (name_to_search == (std["name"]).lower()):
            print("\nStudent found!! \n")

            # Printing Student Details
            print("Name: ", std["name"])
            print("Roll No: ", std["roll"])
            print("Age: ", std["age"], "\n")


def search_by_subject(subject_to_search, students):
    print("-------------------------------")
    print("Name                    Roll   ")
    print("-------------------------------")
    for std in students:
        if subject_to_search in (subject.lower() for subject in std["subjects"]):

            print(f"{std["name"]:<25}", f"{std["roll"]}")


def search_by_skiils(skill_to_search, students):

    print("-------------------------------")
    print("Name                    Roll   ")
    print("-------------------------------")
    for std in students:
        if skill_to_search in (skill.lower() for skill in std["skills"]):
            print(f"{std["name"]:<25}", f"{std["roll"]}")


def search_students(students):

    while (True):
        print("1. Search By Roll Number")
        print("2. Search By Name")
        print("3. Search By Subject")
        print("4. Search By Skills")
        print("5. Back")

        choice2 = int(input("Enter Your Choice: "))

        if (choice2 == 1):
            roll_to_search = int(input("Enter Roll Number to search: "))
            search_by_roll(roll_to_search, students)

        elif (choice2 == 2):
            name_to_search = input("Enter Name to search: ")
            name_to_search = name_to_search.lower()
            search_by_name(name_to_search, students)

        elif (choice2 == 3):
            subject_to_search = input("Enter Subject to search: ")
            subject_to_search = subject_to_search.lower()
            search_by_subject(subject_to_search, students)

        elif (choice2 == 4):
            skill_to_search = input("Enter Skill to search: ")
            skill_to_search = skill_to_search.lower()
            search_by_skiils(skill_to_search, students)

        elif (choice2 == 5):
            break

        else:
            print("Enter Valid Choice")
