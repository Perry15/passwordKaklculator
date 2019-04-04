package Password;
import StartingData.StartingData;
import java.util.Random;
//import java.lang.String;
public class Lev0 extends Password{
	private final int lenMin;
	private String description;
	private Random generator;
	public Lev0(){
		super("0000",4);
		lenMin=4;
		generator = new Random(); 
		description="Una password di livello 0 contiene solo lettere minuscole o solo numeri"
                    + " e possiede una lunghezza minima pari a 4 caratteri.";
	}
	public Lev0(String p){
		super(p,p.length());
		lenMin=4;
		generator = new Random(); 
		description="Una password di livello 0 contiene solo lettere minuscole o solo numeri"
                    + " e possiede una lunghezza minima pari a 4 caratteri.";
	}
	public String getDescription(){
		return description;
	}
	public String combination1(StartingData d1, StartingData d2){
		//LEV0 LUNGHEZZA MINIMA 4 O SOLO LETTERE O SOLO NUMERI
		//corrisponde ad un somma(append) aggiunge a 3 elementi della stringa di d1
		//altri 3 elementi della stringa di d2
		int l=d1.getData().length();
		int r=generator.nextInt(l-2) + 0;
		String p1=d1.getData().substring(r,r+3).toLowerCase();
		l=d2.getData().length();
		r=generator.nextInt(l-2) + 0;
		String p2=d2.getData().substring(r,r+3).toLowerCase();
		setPassword(p1+p2);
		setLength(getPassword().length());
		return p1+p2;
	}
	public String combination2(StartingData d1, StartingData d2){
		//LEV0 LUNGHEZZA MINIMA 4 O SOLO LETTERE O SOLO NUMERI
		//la sottrazione è l'inverso della somma
		//o chiamo combination1 e inverto la stringa ma mi par troppo facile
		int l=d1.getData().length();
		int r=generator.nextInt(l-2) + 0;
		String p1=d1.getData().substring(r,r+3).toLowerCase();
		l=d2.getData().length();
		r=generator.nextInt(l-2) + 0;
		String p2=d2.getData().substring(r,r+3).toLowerCase();
		
		setPassword(inversion(p1)+inversion(p2));//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return inversion(p1)+inversion(p2);
	}
	public String combination3(StartingData d1, StartingData d2){
		//LEV0 LUNGHEZZA MINIMA 4 O SOLO LETTERE O SOLO NUMERI
		//la moltiplicazione prende 3 elementi del primo operando
		//3 del secondo operando e alterna le lettere dei due gruppi
		int l=d1.getData().length();
		int r=generator.nextInt(l-2) + 0;
		String p1=d1.getData().substring(r,r+3).toLowerCase();
		l=d2.getData().length();
		r=generator.nextInt(l-2) + 0;
		String p2=d2.getData().substring(r,r+3).toLowerCase();
		
		//a questo devo creare la stringa alternata
		String ris="",tmp=p1+p2;
		int k,n=tmp.length();
		if(n%2==0)//se è pari ma in lev0 sarà sempre pari perchè 3+3=6
			k=0;//la costante è 0
		else//se la lunghezza è dispari
			k=1;//k è 1 perchè lo aggiungo al primo parametro della mid in modo da
			//tenere un carattere centrale fermo in ris (di solito lunga 9)
		for(int i=0;i<n/2;++i){
			ris+=tmp.substring(i,i+1)+tmp.substring(i+(n/2)+k,(i+(n/2)+k)+1);
		}
		if(k==1){//se la lunghezza era dispari
			//aggiungo il carattere centrale: tmp.substring(n/2,(n/2)+1) 
			//nella pos centrale di ris
			ris=ris.substring(0,n/2) + tmp.substring(n/2,(n/2)+1) + ris.substring(n/2,n-1);
		}
		
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
}