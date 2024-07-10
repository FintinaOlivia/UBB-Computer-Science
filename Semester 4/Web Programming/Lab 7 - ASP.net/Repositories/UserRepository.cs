using FinalBoss.Data;
using FinalBoss.Models;
using Microsoft.EntityFrameworkCore;

namespace FinalBoss.Repositories
{
    public class UserRepository : IUserRepository
    {
        protected readonly ApplicationDbContext _context;

        public UserRepository(ApplicationDbContext context)
        {
            _context = context;
        }

        public async Task<List<Users>> GetUsers()
        {
            var users = await _context.Users.ToListAsync();

            return users ?? new List<Users>();
        }

        public async Task<Users> GetUserById(int id)
        {
            return await _context.Users.FindAsync(id) ?? new Users();
        }

        public async Task<List<Users>> GetUsersByName(string name)
        {
            return await _context.Users.Where(user => user.name.Contains(name)).ToListAsync() ?? new List<Users>();
        }

        public async Task<List<Users>> GetUsersByRole(string role)
        {
            return await _context.Users.Where(user
                => user.role.Contains(role)).ToListAsync() ?? new List<Users>();
        }

        public async Task<List<Users>> GetUsersByBoth(string name, string role)
        {
            return await _context.Users.Where(user 
                => user.name.Contains(name) && user.role.Contains(role))
                .ToListAsync() ?? new List<Users>();
        }

        public void AddUser(Users users)
        {
            _context.Users.Add(users);
            _context.SaveChanges();
        }

        public void UpdateUser(Users users)
        {
            _context.Entry(users).State = EntityState.Modified;
            _context.SaveChanges();
        }

        public void DeleteUser(Users users)
        {
            _context.Users.Remove(users);
            _context.SaveChanges();
        }
    }
}

