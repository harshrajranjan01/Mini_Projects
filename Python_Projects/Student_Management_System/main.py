from result import *
from file_manager import *
from search import *
from student import *
from sort import *

print("==============================")
print("Student Management System")
print("==============================")

# Lists of studetns
students = []

while (True):
                                                                                                                                                                
    # choices
    print("\n1. Add Student")
    print("2. View All Students")
    print("3. Search Students")
    print("4. sort_students: ")
    print("5. update Student details")
    print("6. Delete Student details")
    print("7. Show Result")
    print("8. Save Data")
    print("9. Load Data")
    print("10. Exit \n")

    choice = input("Enter Your Choice: ")

    if choice == "1":
        add_student(students)

    elif choice == "2":
        view_all_students(students)

    elif choice == "3":
        search_students(students)

    elif choice == "4":
        sort_students(students)

    elif choice == "5":
        update_student(students)

    elif choice == "6":
        delete_student(students)

    elif choice == "7":
        show_results(students)

    elif choice == "8":
        save_data(students)

    elif choice == "9":
        load_data(students)

    elif choice == "10":
        print("Exiting Student Management System. Goodbye!")
        break

    else:
        print("Please Enter Valid Choice")
