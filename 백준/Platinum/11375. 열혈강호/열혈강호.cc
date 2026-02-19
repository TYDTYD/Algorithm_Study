#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Employee {
public:
	int id;
	int count_task = 0;
	bool isAssign = false;
	Employee(int id) : id(id) {}
};

class Task {
public:
	int id;
	int count_person = 0;
	vector<Employee*> possible_employees;
	Employee* assign_Employee = nullptr;	
	Task(int id) : id(id) {}
	void AssingTask() {
		sort(possible_employees.begin(), possible_employees.end(), [](Employee* a, Employee* b) {
			return a->count_task < b->count_task;
			});
		for (Employee* employee : possible_employees) {
			if(assign_Employee != nullptr) {
				employee->count_task--;
				continue;
			}
			if (!employee->isAssign && employee->count_task > 0) {
				employee->isAssign = true;
				employee->count_task--;
				assign_Employee = employee;				
				count_person--;				
			}			
		}
	}
};

class Company {
	public:	
		unordered_map<int, Task*> tasks;
		unordered_map<int, Employee*> employees;
		int possible_Task = 0;
		void Solve() {
			vector<Task*> task_Vector;
			for(auto& task : tasks) {
				task_Vector.push_back(task.second);
			}
			sort(task_Vector.begin(), task_Vector.end(), [](Task* a, Task* b) {
				return a->count_person < b->count_person;
				});

			for (auto& task : task_Vector) {
				task->AssingTask();
				if (task->assign_Employee != nullptr) {
					possible_Task++;
				}
			}

			cout << possible_Task;
		}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	Company company;	

	for (int i = 1; i <= n; i++) {
		company.employees.insert({ i, new Employee(i) });
	}
	
	for(int i = 1; i <= m; i++) {				
		company.tasks.insert({ i, new Task(i) });
	}

	for (int i = 1; i <= n; i++) {
		int count;
		cin >> count;
		Employee* employee = company.employees[i];
		for (int j = 0; j < count; j++) {
			int id;
			cin >> id;
			company.tasks[id]->possible_employees.push_back(employee);
			company.tasks[id]->count_person++;
			employee->count_task++;
		}	
	}

	company.Solve();

	return 0;
}