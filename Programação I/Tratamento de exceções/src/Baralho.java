import java.util.Random;

public class Baralho {
    private Carta cartas[] = new Carta[52];

    public Baralho(){
        for(int i=0; i<52;i++){
            cartas[i] = new Carta();
        }
        for(int i=1; i<14;i++){
            switch(i){
                case 1: cartas[i-1].setNumero("ás de ");
                        cartas[i+12].setNumero("ás de ");
                        cartas[i+25].setNumero("ás de ");
                        cartas[i+38].setNumero("ás de ");
                break;
                case 11: cartas[i-1].setNumero("valete de  ");
                         cartas[i+12].setNumero("valete de ");
                         cartas[i+25].setNumero("valete de ");
                         cartas[i+38].setNumero("valete de ");
                break;
                case 12: cartas[i-1].setNumero("dama de ");
                         cartas[i+12].setNumero("dama de ");
                         cartas[i+25].setNumero("dama de ");
                         cartas[i+38].setNumero("dama de ");
                break;
                case 13: cartas[i-1].setNumero("rei de ");
                         cartas[i+12].setNumero("rei de ");
                         cartas[i+25].setNumero("rei de ");
                         cartas[i+38].setNumero("rei de ");
                break;
                default : cartas[i-1].setNumero(Integer.toString(i) +" de ");
                          cartas[i+12].setNumero(Integer.toString(i)+ " de ");  
                          cartas[i+25].setNumero(Integer.toString(i)+ " de ");
                          cartas[i+38].setNumero(Integer.toString(i)+ " de ");
                break;
            }
            cartas[i-1].setNaipe("paus");
            cartas[i+12].setNaipe("copas");
            cartas[i+25].setNaipe("espadas");
            cartas[i+38].setNaipe("ouros");
        }
        for(int i=0;i<52;i++){
            cartas[i].setNome(cartas[i].getNumero()+cartas[i].getNaipe());
        }
    }

    public Carta[] getCartas() {
        return cartas;
    }

    public void encontraCarta(String nome) throws Exception{
        int a = 0;
        for(int i=0;i<52;i++){
            if(cartas[i].getNome().equals(nome)){
                System.out.println("Carta encontrada");
                a = 1;
            }
        }
        if(a==0){
            throw new Exception("A carta informada nao existe");
        }
    }

    public void embaralhar(){
        Random gerador = new Random();
        int i = gerador.nextInt(400,500);
        while(i>0){
            Carta temp1 = new Carta();
            Carta temp2 = new Carta();
            int a,b;
            a = gerador.nextInt(0,51);
            b = gerador.nextInt(0,51);
            temp1 = cartas[a];
            temp2 = cartas[b];
            cartas[a] = temp2;
            cartas[b] = temp1;
            i--;
        }
    }
}
