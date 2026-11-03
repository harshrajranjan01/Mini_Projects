
class result():

    @staticmethod
    def calculate_total(marks):
        return sum(marks)

    @staticmethod
    def calculate_percentage(marks):
        total = result.calculate_total(marks)
        return round(total/len(marks), 2)

    @staticmethod
    def calculate_grade(percentage):
        if percentage >= 90:
            return "A+"
        elif percentage >= 80:
            return "A"
        elif percentage >= 70:
            return "B"
        elif percentage >= 60:
            return "C"
        elif percentage >= 50:
            return "D"
        elif percentage >= 40:
            return "E"
        else:
            return "F"

    @staticmethod
    def calculate_result(marks):
        percentage = result.calculate_percentage(marks)
        grade = result.calculate_grade(percentage)

        if grade == "F":
            return "FAIL"
        else:
            return "PASS"




def show_results(students):
    roll_to_show_result = int(input("Enter Roll No for result: "))
    for std in students:
        if roll_to_show_result == std["roll"]:
            marks = std["marks"]
            total_marks = result.calculate_total(marks)
            print("Total Marks: ", total_marks)

            percentage = result.calculate_percentage(marks)
            print(f"Percentage: {percentage}%")

            grades = result.calculate_grade(percentage)
            print("Grades: ", grades)

            status = result.calculate_result(marks)
            print("student is: ", status)