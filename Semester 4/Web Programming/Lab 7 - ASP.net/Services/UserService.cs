using FinalBoss.Models;
using FinalBoss.Repositories;

namespace FinalBoss.Services
{
    public class UserService : IUserService
    {
        private readonly IUserRepository _userRepository;

        public UserService(IUserRepository userRepository)
        {
            _userRepository = userRepository;
        }

        public async Task<List<Users>> GetUsers()
        {
            return await _userRepository.GetUsers();
        }

        public async Task<Users> GetUserById(int id)
        {
            return await _userRepository.GetUserById(id);
        }

        public async Task<List<Users>> FilterUsersBy(string name, string role)
        {
            if (name != null && role != null)
            {
                return await _userRepository.GetUsersByBoth(name, role);
            }
            else if (name != null)
            {
                return await _userRepository.GetUsersByName(name);
            }
            else if (role != null)
            {
                return await _userRepository.GetUsersByRole(role);
            }
            else
            {
                return await _userRepository.GetUsers();
            }
        }

        public void AddUser(Users users)
        {
            _userRepository.AddUser(users);
        }

        public void UpdateUser(Users users)
        {
            _userRepository.UpdateUser(users);
        }

        public void DeleteUser(Users users)
        {
            _userRepository.DeleteUser(users);
        }
    }
}
