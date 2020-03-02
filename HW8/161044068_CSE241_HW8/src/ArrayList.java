@SuppressWarnings("unchecked")
public class ArrayList<E> implements List<E>{
	private Object[] arr;
	private int capacity,size;

	public ArrayList() {
		size = 0;
		capacity = 100;
		arr = new Object[capacity];
	}
	private Object[] getArray() { return arr; }

	/**
	 *
	 * @return Collectionun iteratorunu return eder.
	 */
	public Iterator<E> iterator() {
		ItrCollection<E> itr = new ItrCollection<E>(arr,size);
		return itr;
	}

	/**
	 * Gelen eleman collection a eklenir.
	 * @param e collectionde eklenemek istenilen eleman
	 */
	public void add(E e) {
		if(size >= capacity) {
			capacity = 2 * capacity;
			Object[] newArr = new Object[capacity];
			for(int i=0; i<size(); ++i)
				newArr[i] = arr[i];
			arr=null;
			arr=newArr;
		}
		arr[size] = e;
		size = size + 1;
	}

	/**
	 *	Gelen collectionun elemanlari collectiona eklenir.
	 * @param c Bu collectiona eklenecek elemanlarin collectionudur.
	 */
	public void addAll(Collection<E> c) {
		Iterator<E> itr = c.iterator();
		while(itr.hasNext()) {
			this.add(itr.next());
		}
	}

	/**
	 * Collectiondaki butun elemanlari siler.Size 0 olur.
	 */
	public void clear() {
		for(int i=0; i<size; i++)
			this.getArray()[i] = null;
		size = 0;
	}

	/**
	 * Gelen elemanin collectionda olup olmadigi kontrol edilir.
	 * @param e Collectionda aranacak elemandir.
	 * @return Eger aranacak olan collectionda varsa true,aksi halde false return edilir.
	 */
	public boolean contains(E e) {
		for(int i=0; i<size; ++i) {
			if(e == this.getArray()[i])
				return true;
		}
		return false;
	}

	/**
	 * Gonderilen collectionun bu collectionda olup olmadigi kontrol edilir.
	 * @param c Elemanlarinin test edilecegi collection
	 * @return Eger collection gonderilen collectionun elemanlarini iceriyorsa
	 * true, aksi halde false return eder.
	 */
	public boolean containsAll(Collection<E> c) {
		boolean temp = false;
		Object temp2;
		Iterator<E> itr = c.iterator();
		while(itr.hasNext()) {
			temp = false;
			temp2 = itr.next();
			for(int j=0; j<this.size(); ++j) {
				if(temp2 == this.getArray()[j])
					temp = true;
			}
			if(temp == false)
	            return false;	
		}
		return temp;
	}

	/**
	 * Collection elemana sahip degilse true return edilir.
	 * @return Collection eleman icermiyorsa true, aksi halde false return edilir.
	 */
	public boolean isEmpty() {
		if(size == 0)
			return true;
		return false;
	}

	/**
	 *
	 * @param e Collectionda var ise collectiondan silinmek istenilen element
	 * @return Eger silinmek istenilen eleman var ise silinir ve true return edilir.
	 */
	public boolean remove(E e) {
		int temp = 0;
		for(int i = 0; i < this.size(); i++){
            if(arr[i] == e){
            	temp = 1;
                // shifting elements
                for(int j = i; j < this.size() - 1; j++){
                    arr[j] = arr[j+1];
                }
                break;
        	}
        }
		if(temp == 1) {
			size--;
			return true;
		}	
		return false;
	}

	/**
	 * Gelen collectionlarin elemanlari bu collactionda varsa silinir.
	 * @param c Collectiondan silinmek istenilen elemanlara sahip olan collection.
	 * @return Gelen collectiondaki elemanlar bu collectiondan silinirse true,
	 * aksi halde false return eder.
	 */
	public boolean removeAll(Collection<E> c) {
		int temp = 0;
		Iterator<E> itr = c.iterator();
		while(itr.hasNext()) {
			for(int j = 0; j < this.size(); j++){
	            if(itr.next() == arr[j]){
	            	temp++;
	                // shifting elements
	                for(int k = j; k < this.size() - 1; k++){
	                    arr[k] = arr[k+1];
	                }
	                size--;
	                break;
	        	}
	        }
		}
		if(temp == ((ArrayList<E>)c).size())
			return true;
		return false;
	}

	/**
	 * Gelen collactiondaki elemanlar disindaki elemanlar bu collectiondan silinir.
	 * @param c Collectionda kalmasi istenilen elemanlarin collectionu
	 * @return Collection degisirse return aksi halde false return edilir.
	 */
	public boolean retainAll(Collection<E> c) {
		boolean temp = false;
	    Object temp2,temp3;
	    for(int i=0; i<this.size(); ++i) {
	        temp2 = this.getArray()[i];
	        temp=false;
	        Iterator<E> itr = c.iterator();
	        while(itr.hasNext()){
	            temp3 = itr.next();
	            if(temp2 == temp3)
	                temp = true;
	        }
	        if(temp == false)
	            this.remove((E)temp2);    
	    }
	    return temp;
	}

	/**
	 *
	 * @return Collectiondaki elemanlarin sayisini return eder.
	 */
	public int size() {
		return size;
	}
}