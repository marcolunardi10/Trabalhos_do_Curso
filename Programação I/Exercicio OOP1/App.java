import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Cliente c1 = new Cliente("Marco", 1);
        Cliente c2 = new Cliente("Antonio", 2);

        System.out.println("Codigo do cliente: " +c1.getCodigo() + "\nNome do cliente: " + c1.getNome());
        System.out.println("----------------------------------------");
        System.out.println("Codigo do cliente: " +c2.getCodigo() + "\nNome do cliente: " + c2.getNome());

        c1.setNome("Andre");
        c1.setCodigo(3);
        c2.setNome("Maria");
        c2.setCodigo(4);

        System.out.println("----------------------------------------");
        System.out.println("Codigo do cliente: " +c1.getCodigo() + "\nNome do cliente: " + c1.getNome());
        System.out.println("----------------------------------------");
        System.out.println("Codigo do cliente: " +c2.getCodigo() + "\nNome do cliente: " + c2.getNome());

        CartaoCredito cartao1 = new CartaoCredito("2244 5577 9988 3344", "12/27");
        CartaoCredito cartao2 = new CartaoCredito("3345 6728 6539 7265", "08/28");
        System.out.println("----------------------------------------");

        System.out.println("Digite o numero atual do cartao");
        String numero = sc.nextLine();
        System.out.println("Digite o novo numero");
        String novoNumero = sc.nextLine();
        cartao1.alteraNumero(numero, novoNumero);

        System.out.println("Informe o nome do cliente para mostrar o numero do cartao");
        String nome = sc.nextLine();

        if(nome.equals(c1.getNome())){
            System.out.println("Numero do cartao: " + cartao1.getNumero(true));
        }else{
            System.out.println(cartao1.getNumero(false));
        }

        System.out.println("Digite a data de vencimento atual do cartao");
        String data = sc.nextLine();
        System.out.println("Digite a nova data");
        String novaData = sc.nextLine();
        cartao2.alteraData(data, novaData);


        System.out.println("Informe o nome do cliente para mostrar a data de validade do cartao");
        nome = sc.nextLine();
        if(nome.equals(c2.getNome())){
            System.out.println("Data de vencimento do cartao: " + cartao2.getData(true));
        }else{
            System.out.println(cartao2.getNumero(false));
        }

        Agencia a1 = new Agencia(7734);

        System.out.println("Agencia numero: " + a1.getNumero());
        

        sc.close();
    }
}
