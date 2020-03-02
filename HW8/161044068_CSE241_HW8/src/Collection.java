public interface Collection<E> {
	public Iterator<E> iterator();
	public void add(E e);
	public void addAll(Collection<E> c);
	public void clear();
	public boolean contains(E e);
	public boolean containsAll(Collection<E> c);
	public boolean isEmpty();
	public boolean remove(E e);        
	public boolean removeAll(Collection<E> c);
	public boolean retainAll(Collection<E> c);
	public int size();
}
