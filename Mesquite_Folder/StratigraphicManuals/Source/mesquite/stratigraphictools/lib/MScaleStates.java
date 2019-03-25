/* Code for stratigraphic tools package (http://mesquiteproject.org/... ).
Copyright 2005 by Sébastien Josse, Thomas Moreau and Michel Laurin.
Based on Mesquite source code copyright 1997-2005 W. & D. Maddison.
Available for Mesquite version 1.06
Disclaimer:  The Mesquite source code is lengthy and we are few.  There are no doubt inefficiencies and goofs in this code. 
The commenting leaves much to be desired. Please approach this source code with the spirit of helping out.
Perhaps with your help we can be more than a few, and make Mesquite better.

Mesquite is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.
Mesquite's web site is http://mesquiteproject.org

This source code and its compiled class files are free and modifiable under the terms of 
GNU Lesser General Public License.  (http://www.gnu.org/copyleft/lesser.html)
*/
package mesquite.stratigraphictools.lib;


import mesquite.lib.*;
import mesquite.lib.characters.*;
//import mesquite.cont.lib.*;


/* ======================================================================== */
/**A class for an array of  continuous character states for many characters, at each of the taxa or nodes.*/
public abstract class MScaleStates extends MCharactersStates implements ItemContainer {
	long id;
	static long totalCreated = 0;
	public MScaleStates (Taxa taxa) {
		super(taxa);
		totalCreated++;
		id = totalCreated;
	}
	
	public long getID(){
		return id;
	}
	/*..........................................  MContinuousStates  ..................................................*/
	/** Indicates the type of character stored */ 
	public Class getStateClass(){
		return ScaleState.class;
	}
	/**returns the corresponding CharacterData subclass*/
	public Class getCharacterDataClass (){
		return ScaleData.class;
	}
	/*..........................................  MContinuousStates  ..................................................*/
	/** returns the name of the type of data stored */
	public String getDataTypeName(){
		return "Scale Data";
	}
	/*..........................................  MContinuousStates  ..................................................*/
	/**returns state of character ic in taxon/node it */
	public abstract double getState (int ic, int it);

	/*..........................................MContinuousStates................*/
	/**returns state of item item of character ic in taxon/node it */
	public abstract double getState (int ic, int it, int item);
	
	/*..........................................MContinuousStates................*/
	public abstract Double2DArray getItem(int index);
	
	/*..........................................MContinuousStates................*/
	public double[][] getMatrix(int index){
		Double2DArray m2da = getItem(index);
		if (m2da==null)
			return null;
		return m2da.getMatrix();
	}
	/*..........................................MContinuousStates................*/
   	public int userQueryItem(String message, MesquiteModule module){
		int numItems =getNumItems();
		String[] items = new String[numItems];
		for (int i=0; i<items.length; i++){
			if (StringUtil.blank(getItemName(i)))
				items[i] = "(unnamed)";
			else
				items[i]= getItemName(i);
		}
		return ListDialog.queryList(module.containerOfModule(), "Select item", message, MesquiteString.helpString,  items, 0);
   	}
	/*..........................................MContinuousStates................*/
	public abstract String getItemName(int index);
	/*..........................................MContinuousStates................*/
	public abstract int getItemNumber(NameReference nr);
	/*..........................................MContinuousStates................*/
	public abstract int getNumberOfItems();
	/*..........................................MContinuousStates................*/
	public int getNumItems(){
		return getNumberOfItems();
	}
	/*..........................................MContinuousStates................*/
	public boolean allCombinable(){
		for (int item = 0; item < getNumberOfItems(); item ++)
			for (int ic = 0; ic < getNumChars(); ic++)
				for (int it = 0; it<getNumNodes(); it++) {
					if (!MesquiteDouble.isCombinable(getState(ic, it, item)))
						return false;
				}
		return true;
	}
	/*..........................................MContinuousStates................*/
	public boolean allCombinable(int item){
		for (int ic = 0; ic < getNumChars(); ic++)
			for (int it = 0; it<getNumNodes(); it++) {
				if (!MesquiteDouble.isCombinable(getState(ic, it, item)))
					return false;
			}
		return true;
	}
	/*..........................................MContinuousStates................*/
	public NameReference getItemReference(int n){
		return NameReference.getNameReference(getItemName(n));
	}
	/*..........................................MContinuousStates................*/
	public NameReference getItemReference(String name){
		return NameReference.getNameReference(name);
	}
	/*..........................................MContinuousStates................*/
	/** get CharacterState at node N*/
	public CharacterState getCharacterState (CharacterState cs, int ic, int it){  
		ScaleState c;
		if (cs !=null && cs instanceof ScaleState)
			c = (ScaleState)cs;
		else
			c = new ScaleState(); 
		c.setItemsAs(this);
		for (int item = 0; item<getNumberOfItems(); item++)
			c.setValue(item, getState(ic, it, item));
		return c;
	}
	/*..........................................MContinuousDistribution................*/
   	public String toString(){
   		return "Scale matrix (" + getClass().getName() + ") id: " + getID() + " Period: " + getNumTaxa() + " items " + getNumItems();
   	}
}
