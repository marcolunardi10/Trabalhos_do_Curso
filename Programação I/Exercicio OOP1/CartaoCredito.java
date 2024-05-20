
public class CartaoCredito {
    private String numero;
    private String dataValidade;

    public CartaoCredito(String numero, String dataValidade){
        this.numero = numero;
        this.dataValidade = dataValidade;
    }

    public void alteraNumero(String numero, String novoNumero){
        if(this.numero.equals(numero)){
            this.numero = novoNumero;
            System.out.println("Numero alterado com sucesso");
        }else{
            System.out.println("Numero invalido, operação nao concluida");
        }
    }   
    
    public String getNumero(boolean nome){
        if(nome == true){
            return this.numero;
        }else{
            return "Nome invalido";
        }
    }

    public void alteraData(String dataValidade, String novaData){
        if(this.dataValidade.equals(dataValidade)){
            this.dataValidade = novaData;
            System.out.println("Data alterada com sucesso");
        }else{
            System.out.println("Data invalido, operação nao concluida");
        }
    }

    public String getData(boolean data){
        if(data == true){
            return this.dataValidade;
        }else{
            return "Data invalida";
        }
    }

}
