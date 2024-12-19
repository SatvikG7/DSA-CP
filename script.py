import os
import sys
import subprocess


def create_codeforces_files(contest_code, num_problems):
    contest_dir = f"Codeforces/{contest_code}"
    os.makedirs(contest_dir, exist_ok=True)

    for i in range(num_problems):
        problem = chr(ord("A") + i)
        problem_dir = f"{contest_dir}/{problem}"
        os.makedirs(problem_dir, exist_ok=True)

        with open(f"{problem_dir}/main.cpp", "w") as f:
            f.write(
                "#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n\n\treturn 0;\n}\n"
            )

    print(f"Files created for contest {contest_code}")
    return


def create_leetcode_files(problem_name):
    problem_dir = f"Leetcode/{problem_name}"
    os.makedirs(problem_dir, exist_ok=True)

    with open(f"{problem_dir}/main.cpp", "w") as f:
        f.write(
            "#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n\n\treturn 0;\n}\n"
        )

    with open(f"{problem_dir}/README.md", "w") as f:
        f.write(f"# {problem_name}\n\n")

    print(f"Files created for problem {problem_name}")
    return


def main():
    print("1. Codeforces")
    print("2. Leetcode")
    choice = input("Platform: ")

    if choice == "1":
        contest_code = input("Enter contest code: ")
        num_problems = int(input("Enter number of problems: "))
        create_codeforces_files(contest_code, num_problems)
    elif choice == "2":
        problem_name = input("Enter problem name: ")
        create_leetcode_files(problem_name)
    else:
        print("Invalid choice")
    return


if __name__ == "__main__":
    main()
