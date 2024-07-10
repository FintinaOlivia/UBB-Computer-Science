using FinalBoss.Models;

namespace FinalBoss.Services
{
    public interface IUserService
    {
        Task<List<Users>> GetUsers();
        Task<Users> GetUserById(int id);
        Task<List<Users>> FilterUsersBy(string name, string role);
        void AddUser(Users users);
        void UpdateUser(Users users);
        void DeleteUser(Users users);
    }
}
