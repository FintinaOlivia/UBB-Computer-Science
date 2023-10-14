import controller.Controller;
import repository.Repository;
import tests.TestController;
import tests.TestModule;
import tests.TestRepository;
import view.View;

public class Main {
    public static void main(String[] args) {
        Repository repository = new Repository();
        Controller controller = new Controller(repository);
        View view = new View(controller);
        view.run();
    }

}