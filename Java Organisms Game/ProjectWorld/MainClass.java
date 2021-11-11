package ProjectWorld;
import java.awt.EventQueue;
/**
 *
 * @author kprze
 */
public class MainClass {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
                            new WorldManager(8,8);
			}
        });
    }
}
