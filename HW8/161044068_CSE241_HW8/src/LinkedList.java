@SuppressWarnings({ "unchecked" })
public class LinkedList<E> implements List<E>,Queue<E>{
	private Object[] arr;
	private int capacity,size;
	private Object head;
	public LinkedList() {
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
	 * Gelen element collection a eklenir.
	 * @param e collectionde eklenemek istenilen eleman.
	 * @throws IllegalStateException Eger collection doluysa firlatilir.
	 */
	public void add(E e) throws IllegalStateException{
		if (offer(e))
	        return;
	    else
	        throw new IllegalStateException("LinkedList is full");
	}

	/**
	 * Gelen collectionun elemanlari collectiona eklenir.
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
		while(!(this.isEmpty()))
			this.remove();
	}

	/**
	 * Gelen elemanin collectionda olup olmadigi kontrol edilir.
	 * @param e Collectionda aranacak elemandir.
	 * @return Eger aranacak olan collectionda varsa true,aksi halde false return edilir.
	 */
	public boolean contains(Object e) {
		for(int i=0; i<size; ++i) {
			if(e == this.getArray()[i])
				return true;
		}
		return false;
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
	 * Collectionun head i silinir.
	 * @return Collection silinmeden onceki head return edilir.
	 */
	public E remove() {
		if(size == 0)
			return null;
		Object temp = arr[0];
		for (int i=0; i <size(); i++)
        {
            arr[i] = arr[i + 1];
        }
		size--;
		head = arr[0];
		return (E)temp;
	}

	/**
	 *
	 * @return Collectiondaki elemanlarin sayisini return eder.
	 */
	public int size() {
		return size;
	}

	/**
	 *
	 * @return Collection bos degilse head return edilir.
	 */
	public E element() {
		if(size == 0)
			return null;
		return (E)arr[0];
	}

	/**
	 *
	 * @param e Collectiona eklenmek istenilen eleman.
	 * @return Gelen eleman eklenirse true,aksi halde false return edilir.
	 */
	public boolean offer(Object e) {
		if(size >= capacity) {
			return false;
		}
		arr[size] = e;
		size++;
		return true;
	}

	/**
	 *
	 * @return Silinen eleman return edilir.
	 * @throws IllegalStateException Eger collection bossa bu exception firlatilir.
	 */
	public E poll() throws IllegalStateException{
		if(size == 0)
			throw new IllegalStateException("LinkedList is Empty.");
		Object temp = head;
		this.remove();
		return (E)temp;
	}

	/**
	 * Gonderilen collectionun bu collectionda olup olmadigi kontrol edilir.
	 * @param c Elemanlarinin test edilecegi collection
	 * @return Eger collection gonderilen collectionun elemanlarini iceriyorsa
	 * true, aksi halde false return eder.
	 */
	public boolean containsAll(Collection<E> c) {
		Iterator<E> itr = c.iterator();
		while(itr.hasNext()) {
            if (!contains(itr.next()))
                return false;
		}
        return true;
	}

	/**
	 * Gelen collectionlarin elemanlari bu collactionda varsa silinir.
	 * @param c Collectiondan silinmek istenilen elemanlara sahip olan collection.
	 * @return Gelen collectiondaki elemanlar bu collectiondan silinirse true,
	 * aksi halde false return eder.
	 */
	public boolean removeAll(Collection<E> c) {
		int temp = 0;
		Object temp2;
		Iterator<E> itr = c.iterator();
		while(itr.hasNext()){
			temp2 = itr.next();
			for(int j = 0; j < this.size(); j++){
	            if(temp2 == arr[j]){
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
		if(temp == ((HashSet<E>)c).size())
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
	        while(itr.hasNext()) {
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
	 * @param e Collectionda var ise collectiondan silinmek istenilen eleman
	 * @return Eger silinmek istenilen eleman var ise silinir ve true return edilir.
	 */
	public boolean remove(E e) {
		if(e != head)
			return false;
		this.remove();
		return true;
	}
	
	
}
