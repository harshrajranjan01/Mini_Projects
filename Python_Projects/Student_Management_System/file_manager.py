
def save_data(students):
    with open("data/student.txt", "w", encoding="utf-8") as file:
        for std in students:
            name = std["name"]
            roll = str(std["roll"])
            age = str(std["age"])
            subjects = ",".join(std["subjects"])
            marks = ",".join(str(mark) for mark in std["marks"])
            skills = ",".join(std["skills"])

            record = (f"{name}|{roll}|{age}|{subjects}|{marks}|{skills}")

            file.write(record + "\n")


def load_data(students):
    loaded_students = []
    try:
        with open("data/student.txt", "r", encoding="utf-8") as file:
            for line in file:
                line = line.strip()

                if not line:
                    continue

                field = line.split("|")
                name = field[0]
                roll = int(field[1])
                age = int(field[2])
                subjects = tuple(field[3].split(",") if field[3] else ())
                marks = [int(mark)
                         for mark in field[4].split(",")] if field[4] else []
                skills = set(field[5].split(",")) if field[5] else set()

                student = {
                    "roll": roll,
                    "name": name,
                    "age": age,
                    "subjects": subjects,
                    "marks": marks,
                    "skills": skills
                }

                loaded_students.append(student)

        # Replace current records instead of duplicating them
        students.clear()
        students.extend(loaded_students)

        print(f"{len(students)} student record(s) loaded successfully!")

    except FileNotFoundError:
        print("students.txt not found. Save data or create the file first.")

    except ValueError:
        print("Invalid numeric data found in the file.")
