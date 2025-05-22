#include <iostream> 

const int MAX_SUBJECTS = 5;
const int MAX_STUDENTS = 30;

struct grade_scale {  
    int min_score;
    int max_score;
    char grade_label[20];
};

struct subject {
    int id;
    char name[50];
    int credits;
};

struct teacher {
    int id;
    char name[50];
    char department[50];
    int subject_ids[MAX_SUBJECTS];
    int subject_count;
};

struct student {
    int id;
    char name[50];
    int group_id;
};

struct group {
    int id;
    char name[50];
    int student_ids[MAX_STUDENTS];
    int student_count;
};

struct grade_report {
    int student_id;
    int subject_id;
    int teacher_id;
    int score;
};

void print_subject(const subject& s) {
    std::cout << "Subject: " << s.name << " (" << s.credits << " credits)\n";
}

void print_student(const student& s) {
    std::cout << "Student: " << s.name << ", Group ID: " << s.group_id << "\n";
}

void print_teacher(const teacher& t) {
    std::cout << "Teacher: " << t.name << ", Department: " << t.department << "\n";
}

int main() {
    subject comp_sci = {1, "Computer Science", 5};
    teacher teacher_1 = {1, "Kuzmich A.A.", "Computer Science Dept", {1}, 1};
    student student_1 = {1, "Bordei V.S.", 101};
    group group_1 = {101, "Group IPZ-21", {1}, 1};
    grade_report report_1 = {1, 1, 1, 92};
    grade_scale scale_a = {90, 100, "Excellent"};

    print_subject(comp_sci);
    print_teacher(teacher_1);
    print_student(student_1);

    return 0;
}
