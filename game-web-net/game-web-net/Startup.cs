using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(game_web_net.Startup))]
namespace game_web_net
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
