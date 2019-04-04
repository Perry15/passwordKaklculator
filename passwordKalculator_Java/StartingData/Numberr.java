package StartingData;
import Exception.MyException;
public class Numberr extends StartingData{
	private String numb;
	
    public Numberr(String n){
		super(5);
		numb=n;
	}
	public String getNumber(){
		return numb;
	}
	@Override
	public String getData(){
		return numb;
	}
	@Override
	public boolean checkLength(){
		String s="0";
		if(numb.length()<3)
			numb = new String(new char[3-numb.length()]).replace("\0", s) + numb;
		return true;
	}
	@Override
	public void validate() throws MyException{
		//tolgo spazi
		numb=numb.replaceAll("\\s+","");
		checkLength();//meglio controllare la lunghezza dopo aver tolto gli spazi
		//controllo che non ci siano numeri o caratteri speciali
		if(!numb.matches("[0-9]+")){
			throw new MyException("Numero non valido,\nsono consentiti solo numeri");
		}
	}

}