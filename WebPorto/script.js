// Smooth scroll for navigation links with an offset to account for the fixed header
document.querySelectorAll('nav a[href^="#"]').forEach(anchor => {
  anchor.addEventListener('click', function (e) {
      e.preventDefault();
      const target = document.querySelector(this.getAttribute('href'));
      window.scrollTo({
          top: target.offsetTop - 100,  // Offset for the fixed header
          behavior: 'smooth'
      });
  });
});

// Contact form submission with validation
document.getElementById("contact-form").addEventListener("submit", function(event) {
  event.preventDefault();

  // Get form values
  var name = document.getElementById("name").value;
  var email = document.getElementById("email").value;
  var message = document.getElementById("message").value;

  // Simple form validation
  if (name === "" || email === "" || message === "") {
    alert("Please fill out all fields.");
  } else {
    alert("Thank you, " + name + "! Your message has been sent.");
    
    // Clear the form
    document.getElementById("contact-form").reset();
  }
});

