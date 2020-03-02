public interface Queue<E> extends Collection<E>{
	public E element();
	public boolean offer(E e);
	public E poll();
}
