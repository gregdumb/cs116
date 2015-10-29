#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
public:
   /**
      Constructs an employee with empty name and no salary.
   */

   Employee();  // default contructor need to initialize salary to 0
   /**
      Constructs an employee with a given name and salary.
      @param employee_name the employee name (set name = employee_name)
      @param initial_salary the initial salary (set salary to initial_salary)
   */

   Employee(string name, double initialSalary);

   /**
      Gets the salary of this employee.
      @return the current salary
   */
   double getSalary() const;

   /**
      Sets the salary of this employee.
      @param new_salary the new salary value
   */
   void setSalary(double newSalary);

   /**
      Gets the name of this employee.
      @return the employee name
   */
   string getName() const;
private:
   string name;
   double salary;
};

#endif
