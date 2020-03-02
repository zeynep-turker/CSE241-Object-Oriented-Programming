public class test{

	public static void main(String[] args) {
		/**
		 *  Butun collectionlar String ve Integer icin test edilmistir.
		 */
		int i;
		try {
			
			//HashSet<String> Testing..
			
			System.out.println("HashSet<String> Testing..");
			HashSet<String> h1 = new HashSet<String>();
			HashSet<String> h2 = new HashSet<String>();
			h1.add("One"); //Add()
			h1.add("Two");
			h1.add("Three");
			System.out.println("\nAfter add() functions.. ");
			Iterator<String> h1Itr = h1.iterator();
			i=0;
			while(h1Itr.hasNext()) {
				System.out.printf("h1[%d] -> %s ",i,h1Itr.next());
				++i;
			}
			System.out.println();
			System.out.println("\nAfter h1.contains('One') function..");
			if(h1.contains("One")) //contains(e)
				System.out.printf("There is 'One' in h1.\n");
			h2.addAll(h1); //addAll(e)
			System.out.println("\nAfter h2.addAll(h1) function..");
			Iterator<String> h2Itr = h2.iterator();
			i=0;
			while(h2Itr.hasNext()) {
				System.out.printf("h2[%d] -> %s ",i,h2Itr.next());
				++i;
			}
			System.out.println();
			h2.add("Four");
			System.out.println("\nAfter adding 'Four' in h2.");
			h2Itr = h2.iterator();
			i=0;
			while(h2Itr.hasNext()) {
				System.out.printf("h2[%d] -> %s ",i,h2Itr.next());
				++i;
			}
			System.out.println("\n\nAfter h2.contains(h1) function..");
			if(h2.containsAll(h1)) //containsAll()
				System.out.printf("There is h1 elements in h2.\n");	
			System.out.println("\nAfter h2.remove('One') function..");
			if(h2.remove("One")) //remove()
				System.out.printf("'One' is deleted from h2.\n");
			System.out.println("h2 elements : ");
			h2Itr = h2.iterator();
			i=0;
			while(h2Itr.hasNext()) {
				System.out.printf("h2[%d] -> %s ",i,h2Itr.next());
				++i;
			}
			System.out.println();
			h2.add("One");
			System.out.println("\nAfter h2.removeAll(h1) function..");
			if(h2.removeAll(h1)) //removeAll()
				System.out.printf("h1's elements are deleted from h2.\n");
			System.out.println("h2 elements : ");
			h2Itr = h2.iterator();
			i=0;
			while(h2Itr.hasNext()) {
				System.out.printf("h2[%d] -> %s ",i,h2Itr.next());
				++i;
			}
			System.out.println();
			h2.add("One");
			h2.add("Two");
			System.out.println("\nAfter adding 'One' and 'Two' in h2.");
			h2Itr = h2.iterator();
			i=0;
			while(h2Itr.hasNext()) {
				System.out.printf("h2[%d] -> %s ",i,h2Itr.next());
				++i;
			}
			System.out.println("\n\nAfter h2.retainAll(h1) function..");
			if(h2.retainAll(h1)) //retainAll()
				System.out.printf("Retain only h1's elements in h2.\n");
			h2Itr = h2.iterator();
			i=0;
			while(h2Itr.hasNext()) {
				System.out.printf("h2[%d] -> %s ",i,h2Itr.next());
				++i;
			}
			h2.clear();
			System.out.println("\n\nAfter h2.clear() function..");
			System.out.println("h2 has not elemets.\n\n");
			h2Itr = h2.iterator();
			i=0;
			while(h2Itr.hasNext()) {
				System.out.printf("h2[%d] -> %s ",i,h2Itr.next());
				++i;
			}
			System.out.println("*************************");
			//HashSet<Integer> Testing..

			System.out.println("\n\nHashSet<Integer> Testing..");
			HashSet<Integer> h3 = new HashSet<Integer>();
			HashSet<Integer> h4 = new HashSet<Integer>();
			h3.add(1); //Add()
			h3.add(2);
			h3.add(3);
			System.out.println("\nAfter add() functions..");
			Iterator<Integer> h3Itr = h3.iterator();
			for(i=0; h3Itr.hasNext(); ++i)
				System.out.printf("h3[%d] -> %d ",i,h3Itr.next());
			System.out.println("\n\nAfter h3.contains(1) functions..");
			if(h3.contains(1)) //contains(e)
				System.out.printf("There is 1 in h3.\n");
			h4.addAll(h3); //addAll(e)
			System.out.println("\nAfter h4.addAll(h3) functions..");
			Iterator<Integer> h4Itr = h4.iterator();
			for(i=0; h4Itr.hasNext(); ++i)
				System.out.printf("h4[%d] -> %d ",i,h4Itr.next());
			h4.add(4);
			System.out.println("\n\nAfter adding '4' in h4.");
			h4Itr = h4.iterator();
			for(i=0; h4Itr.hasNext(); ++i)
				System.out.printf("h4[%d] -> %d ",i,h4Itr.next());
			System.out.println("\n\nAfter h4.containsAll(h3) functions..");
			if(h4.containsAll(h3)) //containsAll()
				System.out.printf("There is h3 elements in h4.\n");
			System.out.println("\nAfter h4.remove(1) functions..");
			if(h4.remove(1)) //remove()
				System.out.printf("1 is deleted from h4.\n");
			h4Itr = h4.iterator();
			for(i=0; h4Itr.hasNext(); ++i)
				System.out.printf("h4[%d] -> %d ",i,h4Itr.next());
			h4.add(1);
			System.out.println("\n\nAfter h4.removeAll(h3) functions..");
			if(h4.removeAll(h3)) //removeAll()
				System.out.printf("h3's elements are deleted from h3.\n");
			h4Itr = h4.iterator();
			for(i=0; h4Itr.hasNext(); ++i)
				System.out.printf("h4[%d] -> %d ",i,h4Itr.next());
			System.out.println();
			h4.add(1);
			h4.add(2);
			System.out.println("\nAfter adding 1 and 2 in h4.");
			h4Itr = h4.iterator();
			for(i=0; h4Itr.hasNext(); ++i)
				System.out.printf("h4[%d] -> %d ",i,h4Itr.next());
			System.out.println("\n\nAfter h4.retainAll(h3) functions..");
			if(h4.retainAll(h3)) //retainAll()
				System.out.printf("Retain only h3's elements in h4.\n");
			h4Itr = h4.iterator();
			for(i=0; h4Itr.hasNext(); ++i)
				System.out.printf("h4[%d] -> %d ",i,h4Itr.next());
			h4.clear();
			System.out.println("\n\nAfter h4.clear() functions..");
			System.out.println("h4 has not elemets.\n\n");
			h4Itr = h4.iterator();
			for(i=0; h4Itr.hasNext(); ++i)
				System.out.printf("h4[%d] -> %d \n\n",i,h4Itr.next());
		}
		catch(IllegalArgumentException e) {
			System.out.println("Entered wrong Argument!");
		}
		try {
			System.out.println("*************************");
			//LinkedList<Integer> Testing..
			
			System.out.println("\n\nLinkedList<Integer> Testing..");
			LinkedList<Integer> l1 = new LinkedList<Integer>();
			LinkedList<Integer> l2 = new LinkedList<Integer>();
			for(i=1; i<5; ++i)
				l1.add(i); //add(e)
			System.out.println("\nAfter add() functions..");
			Iterator<Integer> l1Itr = l1.iterator();
			for(i=0; l1Itr.hasNext(); ++i)
				System.out.printf("l1[%d] -> %d ",i,l1Itr.next());
			l2.addAll(l1); //addAll()
			System.out.println("\n\nAfter l2.addAll(l1) function..");
			Iterator<Integer> l2Itr = l2.iterator();
			for(i=0; l2Itr.hasNext(); ++i)
				System.out.printf("l2[%d] -> %d ",i,l2Itr.next());
			l2.remove(); //remove()
			System.out.println("\n\nAfter l2.remove() function..");
			l2Itr = l2.iterator();
			for(i=0; l2Itr.hasNext(); ++i)
				System.out.printf("l2[%d] -> %d ",i,l2Itr.next());
			System.out.println("\n\nAfter l4.element() function..");
			System.out.printf("l2's head is %d ",l2.element()); //element()
			l2.offer(5); //offer()
			System.out.println("\n\nAfter l2.offer(5) function..");
			l2Itr = l2.iterator();
			for(i=0; l2Itr.hasNext(); ++i)
				System.out.printf("l2[%d] -> %d ",i,l2Itr.next());
			l2.poll(); //poll()
			System.out.println("\n\nAfter l2.poll(); function..");
			l2Itr = l2.iterator();
			for(i=0; l2Itr.hasNext(); ++i)
				System.out.printf("l2[%d] -> %d ",i,l2Itr.next());
			System.out.println("\n\nAfter l4.element() function..");
			System.out.printf("l2's head is %d ",l2.element()); //element()
			l2.remove(3);
			System.out.println("\n\nAfter l2.remove(3) function..");
			l2Itr = l2.iterator();
			for(i=0; l2Itr.hasNext(); ++i)
				System.out.printf("l2[%d] -> %d ",i,l2Itr.next());
			l2.clear();
			System.out.println("\n\nAfter l2.clear() function..");
			if(l2.isEmpty()) //isEmpty()
				System.out.println("l2 is empty.\n\n");
			
			System.out.println("*************************");
			//LinkedList<String> Testing..
			
			System.out.println("\n\nLinkedList<String> Testing..");
			LinkedList<String> l3 = new LinkedList<String>();
			LinkedList<String> l4 = new LinkedList<String>();
			l3.add("One");
			l3.add("Two");
			l3.add("Three");
			l3.add("Four");
			System.out.println("\nAfter add() functions..");
			Iterator<String> l3Itr = l3.iterator();
			for(i=0; l3Itr.hasNext(); ++i)
				System.out.printf("l3[%d] -> %s ",i,l3Itr.next());
			l4.addAll(l3); //addAll()
			System.out.println("\n\nAfter l4.addAll(l1) function..");
			Iterator<String> l4Itr = l4.iterator();
			for(i=0; l4Itr.hasNext(); ++i)
				System.out.printf("l4[%d] -> %s ",i,l4Itr.next());
			l4.remove(); //remove()
			System.out.println("\n\nAfter l4.remove() function..");
			l4Itr = l4.iterator();
			for(i=0; l4Itr.hasNext(); ++i)
				System.out.printf("l4[%d] -> %s ",i,l4Itr.next());
			System.out.println("\n\nAfter l4.element() function..");
			System.out.printf("l4's head is %s ",l4.element()); //element()
			l4.offer("Five"); //offer()
			System.out.println("\n\nAfter l4.offer(\"Five\") function..");
			l4Itr = l4.iterator();
			for(i=0; l4Itr.hasNext(); ++i)
				System.out.printf("l4[%d] -> %s ",i,l4Itr.next());
			l4.poll(); //poll()
			System.out.println("\n\nAfter l4.poll() function..");
			l4Itr = l4.iterator();
			for(i=0; l4Itr.hasNext(); ++i)
				System.out.printf("l4[%d] -> %s ",i,l4Itr.next());
			System.out.println("\n\nAfter l4.element() function..");
			System.out.printf("l4's head is %s ",l4.element()); //element()
			l4.remove("Three");
			System.out.println("\n\nAfter l4.remove(\"Three\") function..");
			l4Itr = l4.iterator();
			for(i=0; l4Itr.hasNext(); ++i)
				System.out.printf("l4[%d] -> %s ",i,l4Itr.next());
			l4.clear();
			System.out.println("\n\nAfter l4.clear() function..");
			if(l4.isEmpty()) //isEmpty()
				System.out.println("l4 is empty.\n\n");
		}
		catch(IllegalStateException e) {
			System.out.println("It cannot that same elements in HashSet.");
		}
		System.out.println("*************************");
		//ArrayList<Integer> Testing..
		
		System.out.println("\nArrayList<Integer> Testing..");
		ArrayList<Integer> a1 = new ArrayList<Integer>();
		ArrayList<Integer> a2 = new ArrayList<Integer>();
		for(i=1; i<5; ++i)
			a1.add(i); //add()
		System.out.println("\nAfter add() functions..");
		Iterator<Integer> a1Itr = a1.iterator();
		for(i=0; a1Itr.hasNext(); ++i)
			System.out.printf("a1[%d] -> %d ",i,a1Itr.next());
		System.out.println();
		a2.addAll(a1); //addAll()
		System.out.println("\nAfter a2.addAll(a1) functions..");
		Iterator<Integer> a2Itr = a2.iterator();
		for(i=0; a2Itr.hasNext(); ++i)
			System.out.printf("a2[%d] -> %d ",i,a2Itr.next());
		System.out.println();
		System.out.println("\nAfter a2.contains(1) function..");
		if(a2.contains(1)) //contains()
			System.out.println("a2 contains 1.");
		else
			System.out.println("a2 don't contain 1.");
		a2.add(5);
		System.out.println("\nAfter a2.add(5) function..");
		a2Itr = a2.iterator();
		for(i=0; a2Itr.hasNext(); ++i)
			System.out.printf("a2[%d] -> %d ",i,a2Itr.next());
		System.out.println();
		System.out.println("\nAfter a2.containsAll(a1) function..");
		if(a2.containsAll(a1)) //containsAll()
			System.out.println("a2 contains a1 elements.");
		else 
			System.out.println("a2 don't contain a1 elements.");
		a2.remove(3); //remove()
		System.out.println("\nAfter a2.remove(3) function..");
		a2Itr = a2.iterator();
		for(i=0; a2Itr.hasNext(); ++i)
			System.out.printf("a2[%d] -> %d ",i,a2Itr.next());
		System.out.println();
		a2.removeAll(a1); //removeAll()
		System.out.println("\nAfter a2.removeAll(a1) function..");
		a2Itr = a2.iterator();
		for(i=0; a2Itr.hasNext(); ++i)
			System.out.printf("a2[%d] -> %d ",i,a2Itr.next());
		System.out.println();
		a2.add(1);
		a2.add(2);
		a2.add(3);
		a2.add(4);
		System.out.println("\nAfter add(1),add(2),add(3),add(4) functions..");
		a2Itr = a2.iterator();
		for(i=0; a2Itr.hasNext(); ++i)
			System.out.printf("a2[%d] -> %d ",i,a2Itr.next());
		System.out.println();
		a2.retainAll(a1); //retainAll()
		System.out.println("\nAfter a2.retainAll(a1) function..");
		a2Itr = a2.iterator();
		for(i=0; a2Itr.hasNext(); ++i)
			System.out.printf("a2[%d] -> %d ",i,a2Itr.next());
		System.out.println();
		a2.clear(); //clear()
		System.out.println("\nAfter a2.clear() function..");
		if(a2.isEmpty()) //isEmpty()
			System.out.println("a2 is empty.\n\n");
		
		System.out.println("*************************");
		//ArrayList<String> Testing..
		
		System.out.println("\n\nArrayList<String> Testing..");
		ArrayList<String> a3 = new ArrayList<String>();
		ArrayList<String> a4 = new ArrayList<String>();
		a3.add("One");	//add()
		a3.add("Two");
		a3.add("Three");
		a3.add("Four");
		System.out.println("\nAfter add() functions..");
		Iterator<String> a3Itr = a3.iterator();
		for(i=0; a3Itr.hasNext(); ++i)
			System.out.printf("a3[%d] -> %s ",i,a3Itr.next());
		System.out.println();
		a4.addAll(a3); //addAll()
		System.out.println("\nAfter a4.addAll(a3) functions..");
		Iterator<String> a4Itr = a4.iterator();
		for(i=0; a4Itr.hasNext(); ++i)
			System.out.printf("a4[%d] -> %s ",i,a4Itr.next());
		System.out.println("\n\nAfter a4.contains('One') functions..");
		if(a4.contains("One")) //contains()
			System.out.println("a2 contains 'One'.");
		else
			System.out.println("a2 don't contain 'One'.");
		a4.add("Five");
		System.out.println("\nAfter a4.add(\"Five\") functions..");
		a4Itr = a4.iterator();
		for(i=0; a4Itr.hasNext(); ++i)
			System.out.printf("a4[%d] -> %s ",i,a4Itr.next());
		System.out.println();
		a3Itr = a3.iterator();
		for(i=0; a3Itr.hasNext(); ++i)
			System.out.printf("a3[%d] -> %s ",i,a3Itr.next());
		System.out.println("\n\nAfter a4.containsAll(a3) functions..");
		if(a4.containsAll(a3)) //containsAll()
			System.out.println("a4 contains a3 elements.");
		else 
			System.out.println("a4 don't contain a3 elements.");
		a4.remove("Three"); //remove()
		System.out.println("\nAfter a4.remove('Three') functions..");
		a4Itr = a4.iterator();
		for(i=0; a4Itr.hasNext(); ++i)
			System.out.printf("a4[%d] -> %s ",i,a4Itr.next());
		a4.removeAll(a3); //removeAll()
		System.out.println("\n\nAfter a4.removeAll(a3) function..");
		a4Itr = a4.iterator();
		for(i=0; a4Itr.hasNext(); ++i)
			System.out.printf("a4[%d] -> %s ",i,a4Itr.next());
		a4.add("One");
		a4.add("Two");
		a4.add("Three");
		a4.add("Four");
		System.out.println("\n\nAfter add('One'),add('Two'),add('Three'),add('Four') functions..");
		a4Itr = a4.iterator();
		for(i=0; a4Itr.hasNext(); ++i)
			System.out.printf("a4[%d] -> %s ",i,a4Itr.next());	
		a4.retainAll(a3); //retainAll()
		System.out.println("\n\nAfter a4.retainAll(a3) functions..");
		a4Itr = a4.iterator();
		for(i=0; a4Itr.hasNext(); ++i)
			System.out.printf("a4[%d] -> %s ",i,a4Itr.next());
		System.out.println();
		a4.clear(); //clear()
		System.out.println("\nAfter a4.clear() function..");
		if(a4.isEmpty()) //isEmpty()
			System.out.println("a4 is empty.\n");
	}

}
