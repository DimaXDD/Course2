using Lab2;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9_10wpfef
{
    public class Context : DbContext
    {
        public DbSet<Owner> Owners { get; set; }
        public DbSet<PersonalBill> Bills { get; set; }
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=(local);Initial Catalog=TrueEntity;Integrated Security=True;TrustServerCertificate=true;");
        }

    }
}
