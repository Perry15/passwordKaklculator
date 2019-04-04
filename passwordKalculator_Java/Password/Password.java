package Password;
import StartingData.StartingData;
import java.util.Random;
public abstract class Password{
	private String pwd;
	private int len;
	public Password(String p, int l){
		pwd=p;
		len=l;
	}
	public String getPassword(){
		return pwd;
	}
	public void setPassword(String s){
		pwd=s;
	}
	public int getLength(){
		return len;
	}
	public void setLength(int l){
		len=l;
	}
	public String inversion(String s){
		char v[] =s.toCharArray();
		int n=v.length;
		for(int i=0;i<n/2;++i){
			char tmp=v[i];
			v[i]=v[n-i-1];
			v[n-i-1]=tmp;
		}
		return new String(v);
	}

	public abstract String combination1(StartingData d1, StartingData d2);
    public abstract String combination2(StartingData d1, StartingData d2);
    public abstract String combination3(StartingData d1, StartingData d2);
    
	public abstract String getDescription();
	//getDescription mi serve virtuale perchè con l'oggetto result che ha TS Password(madre)
    //devo chiamare i giusti getPassword in base al TD istanziato
}