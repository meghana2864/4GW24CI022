import java.util.ArrayList;
import java.util.Scanner;

// Contact class
class Contact {
    String name;
    String relation;   // Student / Parent
    String phone;

    Contact(String name, String relation, String phone) {
        this.name = name;
        this.relation = relation;
        this.phone = phone;
    }

    void display() {
        System.out.println("Name     : " + name);
        System.out.println("Relation : " + relation);
        System.out.println("Phone    : " + phone);
        System.out.println("------------------------");
    }
}

// Main class
public class ContactManagementSystem {

    static ArrayList<Contact> contacts = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    // Add contact
    static void addContact() {
        System.out.print("Enter name: ");
        String name = sc.nextLine();

        System.out.print("Enter relation (Student/Parent): ");
        String relation = sc.nextLine();

        System.out.print("Enter phone number: ");
        String phone = sc.nextLine();

        contacts.add(new Contact(name, relation, phone));
        System.out.println("Contact added successfully!\n");
    }

    // Display contacts
    static void displayContacts() {
        if (contacts.isEmpty()) {
            System.out.println("No contacts available.\n");
            return;
        }
        for (Contact c : contacts) {
            c.display();
        }
    }

    // Search contact (Linear Search)
    static void searchContact() {
        System.out.print("Enter name to search: ");
        String key = sc.nextLine();
        boolean found = false;

        for (Contact c : contacts) {
            if (c.name.equalsIgnoreCase(key)) {
                c.display();
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Contact not found.\n");
        }
    }

    // Main menu
    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("===== Student/Parent Contact Management =====");
            System.out.println("1. Add Contact");
            System.out.println("2. Display Contacts");
            System.out.println("3. Search Contact");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = Integer.parseInt(sc.nextLine());

            switch (choice) {
                case 1:
                    addContact();
                    break;
                case 2:
                    displayContacts();
                    break;
                case 3:
                    searchContact();
                    break;
                case 4:
                    System.out.println("Exiting program...");
                    break;
                default:
                    System.out.println("Invalid choice!\n");
            }
        } while (choice != 4);
    }
}