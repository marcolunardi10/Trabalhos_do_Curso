import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Baralho b1 = new Baralho();

        System.out.println("Informe a carta que deseja");
        String c1 = sc.nextLine();
  
        b1.encontraCarta(c1);
        b1.embaralhar();

        for(int i=0;i<51;i++){
            System.out.println(b1.getCartas()[i].getNome());
        }

        sc.close();
    }
}
