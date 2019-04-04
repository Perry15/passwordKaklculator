package StartingData;
import Exception.MyException;
public class NameSurname extends StartingData{
	private String name;
	private String surname;
	
    public NameSurname(String n, String s){
		super(1);//id di NameSurname è 1
		name=n;
		surname=s;
	}
	public String getName(){
		return name;
	}
	public String getSurname(){
		return surname;
	}
	public void setName(String n){
		name=n;
	}
	public void setSurname(String s){
		surname=s;
	}
	@Override
    public String getData(){
		return name+surname;
	}
	@Override
    public boolean checkLength() throws MyException{
		if(name.length()<3 || surname.length()<3)
			throw new MyException("I campi utilizzati per calcolare la password,\ndevono essere lunghi almeno 3 caratteri");
		return true;
	}
	@Override
    public void validate() throws MyException{
		//tolgo spazi
		name=name.replaceAll("\\s+","");
		surname=surname.replaceAll("\\s+","");
		checkLength();//meglio controllare la lunghezza dopo aver tolto gli spazi
		//controllo che non ci siano numeri o caratteri speciali
		if(!name.matches("[a-zA-Z]+")){//se nella stringa non ci sono solo minuscole o maiuscole
			throw new MyException("Nome non valido,\nsono consentite solo lettere");
		}
		if(!surname.matches("[a-zA-Z]+")){//se non ci sono solo minuscole o maiuscole
			throw new MyException("Cognome non valido,\nsono consentite solo lettere");
		}
	}
}