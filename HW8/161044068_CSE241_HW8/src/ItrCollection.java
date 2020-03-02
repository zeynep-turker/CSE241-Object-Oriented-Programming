@SuppressWarnings("unchecked")
public class ItrCollection<E> implements Iterator<E>{
	private Object[] arr;
	private int current,size;

	public ItrCollection(Object[] objects, int size) {
		this.arr = objects;
		current = 0;
		this.size = size;
	}

	/**
	 * Iteratorun gosterdigi yeri kontrol eder.
	 * @return Iterator collection elemanlarini gosteriyorsa true,
	 * aksi halde false retuurn edilir.
	 */
	public boolean hasNext() {
		if(current < size)
			return true;
		return false;
	}

	/**
	 * Iteratorun gelecek elemanini return eder.
	 * @return Iteratorun gelecek elemanini return eder.
	 */
	public E next() {
		if(hasNext() == true)
			return (E)arr[current++];
		return null;
	}

	/**
	 * Iteratorun return ettigi son elemanini siler.
	 */
	public void remove() {
		for(int i=current; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
	}
}
