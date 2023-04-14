using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9_10wpfef
{
    public class Repository<T> : IRepository<T> where T : class
    {
        private readonly Context _context;
        private DbSet<T> _entities;

        public Repository(Context context)
        {
            _context = context;
            _entities = _context.Set<T>();
        }
        public void Add(T entity)
        {
            _entities.Add(entity);
        }
        public void Update(T entity)
        {
            _entities.Update(entity);
        }
        public void Remove(T entity)
        {
            _entities.Remove(entity);
        }
        public IEnumerable<T> GetAll()
        {
            return _entities.ToList();
        }
        public T GetById(int id)
        {
            return _entities.Find(id);
        }
    }

}
