public class StudentController{
    private Student model;
    private StudentView view;

    public StudentController(Student model1, StudentView view1) { model = model1; view = view1; }
    public void setStudentName(String name) { model.setName(name); }
    public String getStudentName() { return model.getName(); }
    public void setStudentRollNo(String rollNo) { model.setRollNo(rollNo); }
    public String getStudentRollNo() { return model.getRollNo(); }
    public void updateView() { view.printStudentDetails(model); }
}