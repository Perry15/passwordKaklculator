package StartingData;
import Exception.MyException;
public class Word extends StartingData{
	private String str;
	
    public Word(String s){
		super(4);
		str=s;
	}
	public String getWord(){
		return str;
	}
	@Override
	public String getData(){
		return str;
	}
	@Override
	public boolean checkLength() throws MyException{
		if(str.length()<3)
			throw new MyException("I campi utilizzati per calcolare la password,\ndevono essere lunghi almeno 3 caratteri");
		return true;
	}
	@Override
	public void validate() throws MyException{
		//tolgo spazi
		str=str.replaceAll("\\s+","");
		checkLength();//meglio controllare la lunghezza dopo aver tolto gli spazi
		//controllo che non ci siano numeri o caratteri speciali
		if(!str.matches("[a-zA-Z]+")){
			throw new MyException("Parola non valida,\nsono consentiti solo numeri");
		}
	}

}