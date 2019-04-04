package Password;
import StartingData.StartingData;
import java.util.Random;
//import java.lang.String;
public class Lev1 extends Password{
	private final int lenMin;
	private String description;
	private Random generator;
	public Lev1(){
		super("000000",6);
		lenMin=6;
		generator = new Random(); 
		description="Una password di livello 1 contiene lettere minuscole e numeri;"
                    + " possiede una lunghezza minima pari a 6 caratteri.";
	}
	public Lev1(String p){
		super(p,p.length());
		lenMin=6;
		generator = new Random(); 
		description="Una password di livello 1 contiene lettere minuscole e numeri;"
                    + " possiede una lunghezza minima pari a 6 caratteri.";
	}
	public String getDescription(){
		return description;
	}
	public String combination1(StartingData d1, StartingData d2){
		//LEV1 LUNGHEZZA MINIMA 6 LETTERE MINUSCOLE E NUMERI
		int l=d1.getData().length();
		int r=generator.nextInt(l-2) + 0;
		String p1=d1.getData().substring(r,r+3).toLowerCase();
		l=d2.getData().length();
		r=generator.nextInt(l-2) + 0;
		String p2=d2.getData().substring(r,r+3).toLowerCase();
		setPassword(p1+p2);
		setLength(getPassword().length());
		String ris = p1+p2;
		
		//se non ci già numeri li aggiungo
		if(ris.matches("[a-z]+")){//se ci sono solo lettere devo aggiungere i numeri
			r=generator.nextInt(100-10) + 10;
			ris+=String.valueOf(r);
		}
		//se non ci sono lettere ovvero ci sono solo numeri, aggiungo 2 lettere casuali
		if(ris.matches("[0-9]+")){//se ci sono solo numeri
			//aggiungo 2 lettere casuali
			String alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
			
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
		}
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
	public String combination2(StartingData d1, StartingData d2){
		//la sottrazione è l'inverso della somma
		//o chiamo combination1 e inverto la stringa ma mi par troppo facile
		int l=d1.getData().length();
		int r=generator.nextInt(l-2) + 0;
		String p1=d1.getData().substring(r,r+3).toLowerCase();
		l=d2.getData().length();
		r=generator.nextInt(l-2) + 0;
		String p2=d2.getData().substring(r,r+3).toLowerCase();
		String ris = inversion(p1)+inversion(p2);
		//se non ci già numeri li aggiungo
		if(ris.matches("[a-z]+")){//se ci sono solo lettere devo aggiungere i numeri
			r=generator.nextInt(100-10) + 10;//-10 perchè facendo + 10 aggiungo 10 anche al massimo
			ris+=String.valueOf(r);
		}
		//se non ci sono lettere ovvero ci sono solo numeri, aggiungo 2 lettere casuali
		if(ris.matches("[0-9]+")){//se ci sono solo numeri
			//aggiungo 2 lettere casuali
			String alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
			
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
		}
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
	public String combination3(StartingData d1, StartingData d2){
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
		
		//se non ci già numeri li aggiungo
		if(ris.matches("[a-z]+")){//se ci sono solo lettere devo aggiungere i numeri
			r=generator.nextInt(100-10) + 10;
			ris+=String.valueOf(r);
		}
		//se non ci sono lettere ovvero ci sono solo numeri, aggiungo 2 lettere casuali
		if(ris.matches("[0-9]+")){//se ci sono solo numeri
			//aggiungo 2 lettere casuali
			String alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
			
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
		}
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
}