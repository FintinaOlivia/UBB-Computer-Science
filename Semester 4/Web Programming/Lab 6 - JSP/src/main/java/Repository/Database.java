package Repository;

import Model.Picture;
import Model.User;
import jakarta.persistence.*;
import jakarta.persistence.criteria.CriteriaBuilder;
import jakarta.persistence.criteria.CriteriaQuery;
import jakarta.persistence.criteria.Root;

import java.util.List;

public class Database {
    private static Database instance;
    private final EntityManagerFactory entityManagerFactory;
    public Database() {
        entityManagerFactory = Persistence.createEntityManagerFactory("default");
    }

    private void checkDatabaseConnection() {
        EntityManager em = null;
        try {
            em = entityManagerFactory.createEntityManager();
            System.out.println("Database connection established successfully.");
        } catch (Exception e) {
            System.err.println("Database connection failed: " + e.getMessage());
            e.printStackTrace();
        } finally {
            if (em != null) {
                em.close();
            }
        }
    }

    public static synchronized Database getInstance() {
        if(instance == null) {
            instance = new Database();
        }
        return instance;
    }

    public User getUserByUsername(String username) {
        EntityManager em = entityManagerFactory.createEntityManager();
        return em.find(User.class, username);
    }

    public User getUserByCredentials(String username, String password) {
        EntityManager em = entityManagerFactory.createEntityManager();
        CriteriaBuilder cb = em.getCriteriaBuilder();
        CriteriaQuery<User> cq = cb.createQuery(User.class);
        Root<User> userRoot = cq.from(User.class);
        cq
                .select(userRoot)
                .where(cb.equal(userRoot.get("username"), username), cb.equal(userRoot.get("password"), password));
        TypedQuery<User> tq = em.createQuery(cq);
        try {
            return tq.getSingleResult();
        } catch(NoResultException exception) {
            return null;
        }
    }

    public void addUser(String username, String name, String password) throws Exception {
        EntityManager em = this.entityManagerFactory.createEntityManager();
        EntityTransaction transaction = em.getTransaction();
        transaction.begin();
        if(em.find(User.class, username) != null) {
            transaction.rollback();
            throw new Exception("Username already exists");
        }
        User user = new User(username, name, password, null);
        em.persist(user);
        transaction.commit();
    }

    public void updateUser(User user) {
        EntityManager em = this.entityManagerFactory.createEntityManager();
        EntityTransaction transaction = em.getTransaction();
        transaction.begin();
        em.merge(user);
        transaction.commit();
    }

    public void addPicture(Picture picture) {
        EntityManager em = this.entityManagerFactory.createEntityManager();
        EntityTransaction transaction = em.getTransaction();
        transaction.begin();
        String username = picture.getUser().getUsername();
        User user = em.find(User.class, username);
        user.getPictures().add(picture);
        em.persist(picture);
        em.merge(user);
        transaction.commit();
    }

    public void updatePicture(Long id, int vote) {
        EntityManager em = this.entityManagerFactory.createEntityManager();
        EntityTransaction transaction = em.getTransaction();
        transaction.begin();
        Picture picture = em.find(Picture.class, id);
        picture.setVotes(picture.getVotes() + vote);
        em.merge(picture);
        transaction.commit();
    }

    public List<Picture> getPicturesOfUser(String username) {
        EntityManager em = this.entityManagerFactory.createEntityManager();
        CriteriaBuilder cb = em.getCriteriaBuilder();
        CriteriaQuery<Picture> cq = cb.createQuery(Picture.class);
        Root<Picture> pictureRoot = cq.from(Picture.class);
        cq
                .select(pictureRoot)
                .where(cb.equal(pictureRoot.get("user"), username));
        TypedQuery<Picture> tq = em.createQuery(cq);
        return tq.getResultList();
    }

    public List<Picture> getTopNMostVotedPictures(int n) {
        EntityManager em = this.entityManagerFactory.createEntityManager();
        CriteriaBuilder cb = em.getCriteriaBuilder();
        CriteriaQuery<Picture> cq = cb.createQuery(Picture.class);
        Root<Picture> pictureRoot = cq.from(Picture.class);
        cq
                .select(pictureRoot)
                .orderBy(cb.desc(pictureRoot.get("votes")));
        TypedQuery<Picture> tq = em.createQuery(cq);
        tq.setMaxResults(n);
        return tq.getResultList();
    }

    public List<Picture> getAllPictures() {
        EntityManager em = entityManagerFactory.createEntityManager();
        CriteriaBuilder cb = em.getCriteriaBuilder();
        CriteriaQuery<Picture> cq = cb.createQuery(Picture.class);
        Root<Picture> pictureRoot = cq.from(Picture.class);
        cq.select(pictureRoot);
        TypedQuery<Picture> tq = em.createQuery(cq);
        return tq.getResultList();
    }
}
