package StartingData;
import Exception.MyException;
public abstract class StartingData {
	private int id;//associa al tipo di operando un numero identificativo
	
	
    public StartingData(int i) {
		id=i;
	}
	
	public final int getId(){//final= non può essere ridefinito sulle sottoclassi
		return id;
	}
	public abstract String getData();//metodo virtuale puro (astratto puro)
	public abstract boolean checkLength() throws MyException;//metodo virtuale puro (astratto puro)
	public abstract void validate() throws MyException;
}