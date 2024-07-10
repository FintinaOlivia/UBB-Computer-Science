using FinalBoss.Models;

namespace FinalBoss.Repositories
{
    public interface IUserRepository
    {
        Task<List<Users>> GetUsers();
        Task<Users> GetUserById(int id);
        Task<List<Users>> GetUsersByName(string name);
        Task<List<Users>> GetUsersByRole(string role);
        Task<List<Users>> GetUsersByBoth(string name, string role);
        void AddUser(Users users);
        void UpdateUser(Users users);
        void DeleteUser(Users users);
    }
}
